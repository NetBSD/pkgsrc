# $NetBSD: options.mk,v 1.4 2011/10/08 13:49:09 shattered Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=		x11 unixodbc ilbc webvmail ldap spandsp
PKG_OPTIONS_LEGACY_OPTS+=	gtk:x11
PKG_SUGGESTED_OPTIONS=		ldap

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11 unixodbc ilbc webvmail ldap spandsp

# gtkconsole depends on GTK 2.x
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/gtk2/buildlink3.mk"
.  include "../../devel/SDL/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sdl
CONFIGURE_ARGS+=	--with-gtk2
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-sdl
CONFIGURE_ARGS+=	--without-gtk2
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
.  include "../../devel/libltdl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ltdl
CONFIGURE_ARGS+=	--with-unixodbc
PLIST.unixodbc=		yes
.else
CONFIGURE_ARGS+=	--without-ltdl
CONFIGURE_ARGS+=	--without-unixodbc
.endif

.if !empty(PKG_OPTIONS:Milbc)
DISTFILES+=		rfc3951.txt
SITES.rfc3951.txt=	http://www.ietf.org/rfc/
DISTFILES+=		extract-cfile.awk
SITES.extract-cfile.awk=	http://www.ilbcfreeware.org/documentation/
USE_TOOLS+=		awk
PLIST.ilbc=		yes
.endif

.if !empty(PKG_OPTIONS:Mspandsp)
.  include "../../comms/spandsp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-spandsp
PLIST.spandsp=		yes
.else
CONFIGURE_ARGS+=	--without-spandsp
.endif

MAKE_FLAGS+=	GLOBAL_MAKEOPTS=${WRKSRC}/pkgsrc.makeopts
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
	# this is a hack to work around a bug in menuselect
	${ECHO} "MENUSELECT_AGIS=agi-test.agi eagi-test eagi-sphinx-test jukebox.agi" >> ${WRKSRC}/pkgsrc.makeopts
	cd ${WRKSRC} && make menuselect.makeopts

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
