# $NetBSD: options.mk,v 1.10 2011/10/08 13:49:09 shattered Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=		x11 unixodbc ilbc webvmail ldap
PKG_OPTIONS_LEGACY_OPTS+=	gtk:x11
PKG_SUGGESTED_OPTIONS=		ldap

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11 unixodbc ilbc webvmail ldap

# gtkconsole depends on GTK 1.x
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/gtk/buildlink3.mk"
.  include "../../devel/SDL/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sdl
CONFIGURE_ARGS+=	--with-gtk
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
.  include "../../devel/libltdl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ltdl
CONFIGURE_ARGS+=	--with-unixodbc
PLIST.unixodbc=		yes
.else
CONFIGURE_ARGS+=	--without-ltdl
CONFIGURE_ARGS+=	--without-odbc
.endif

.if !empty(PKG_OPTIONS:Milbc)
DISTFILES+=		rfc3951.txt
SITES.rfc3951.txt=	http://www.ietf.org/rfc/
DISTFILES+=		extract-cfile.awk
SITES.extract-cfile.awk=	http://www.ilbcfreeware.org/documentation/
USE_TOOLS+=		awk
PLIST.ilbc=		yes
.endif

.if !empty(PKG_OPTIONS:Mx11) || !empty(PKG_OPTIONS:Munixodbc) || !empty(PKG_OPTIONS:Milbc)
RUN_MENUSELECT= # empty
MAKE_FLAGS+=	GLOBAL_MAKEOPTS=${WRKSRC}/pkgsrc.makeopts
.endif
post-configure:
.if !empty(PKG_OPTIONS:Mx11)
	${ECHO} "MENUSELECT_PBX=-pbx_gtkconsole" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if !empty(PKG_OPTIONS:Munixodbc)
	${ECHO} "MENUSELECT_OPTS_app_voicemail=ODBC_STORAGE" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if !empty(PKG_OPTIONS:Milbc)
	${ECHO} "MENUSELECT_CODECS=-codec_ilbc" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if defined(RUN_MENUSELECT)
	# this is a hack to work around a bug in menuselect
	cd ${WRKSRC} && make menuselect.makeopts
.endif

post-extract:
.if !empty(PKG_OPTIONS:Milbc)
	cp ${DISTDIR}/${DIST_SUBDIR}/rfc3951.txt ${WRKSRC}/codecs/ilbc
	cp ${DISTDIR}/${DIST_SUBDIR}/extract-cfile.awk ${WRKSRC}/codecs/ilbc
	cd ${WRKSRC}/codecs/ilbc && ${AWK} -f extract-cfile.awk < rfc3951.txt
.endif

.if !empty(PKG_OPTIONS:Mwebvmail)
DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI
SUBST_CLASSES+=		webvmail
SUBST_STAGE.webvmail=	post-patch
SUBST_FILES.webvmail=	contrib/scripts/vmail.cgi
SUBST_SED.webvmail+=	-e 's|@ASTETCDIR@|${ASTETCDIR}|'
SUBST_SED.webvmail+=	-e "s|@ASTSPOOLDIR@|${ASTSPOOLDIR}|"
INSTALLATION_DIRS+=	${PREFIX}/libexec/cgi-bin ${PREFIX}/share/httpd/htdocs
SPECIAL_PERMS+=		${PREFIX}/libexec/cgi-bin/vmail ${ASTERISK_USER} ${ASTERISK_GROUP} 04555
INSTALL_TARGET+=	webvmail
PLIST.webvmail=		yes
.endif

.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif
