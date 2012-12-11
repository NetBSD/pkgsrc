# $NetBSD: options.mk,v 1.5 2012/12/11 08:22:48 jnemeth Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=		zaptel x11 unixodbc ilbc webvmail ldap spandsp
PKG_SUPPORTED_OPTIONS+=		jabber speex
PKG_OPTIONS_LEGACY_OPTS+=	gtk:x11
PKG_SUGGESTED_OPTIONS=		ldap jabber speex

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		zaptel x11 unixodbc webvmail ldap spandsp jabber
PLIST_VARS+=		speex

# Asterisk now uses DAHDI, not zaptel; not implemented yet...
#.if !empty(PKG_OPTIONS:Mzaptel)
## zaptel only supported under NetBSD at the moment
#.  include "../../comms/zaptel-netbsd/buildlink3.mk"
#PLIST.zaptel=		yes
#.else
#MAKE_FLAGS+=		WITHOUT_ZAPTEL=1
#.endif

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

.if !empty(PKG_OPTIONS:Mspandsp)
.  include "../../comms/spandsp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-spandsp
PLIST.spandsp=		yes
.else
CONFIGURE_ARGS+=	--without-spandsp
.endif

.if !empty(PKG_OPTIONS:Mjabber)
.  include "../../textproc/iksemel/buildlink3.mk"
CONFIGURE_ARGS+=	--with-iksemel=${PREFIX}
PLIST.jabber=		yes
.else
CONFIGURE_ARGS+=	--without-iksemel
.endif

MAKE_FLAGS+=	GLOBAL_MAKEOPTS=${WRKSRC}/pkgsrc.makeopts
post-configure:
.if !empty(PKG_OPTIONS:Mx11)
	${ECHO} "MENUSELECT_PBX=-pbx_gtkconsole" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if !empty(PKG_OPTIONS:Munixodbc)
	${ECHO} "MENUSELECT_OPTS_app_voicemail=ODBC_STORAGE" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if defined(PLIST.mgcp)
	${ECHO} "MENUSELECT_RES=-res_pktccops" >> ${WRKSRC}/pkgsrc.makeopts
	${ECHO} "MENUSELECT_CHANNELS=-chan_mgcp" >> ${WRKSRC}/pkgsrc.makeopts
.endif
	${ECHO} "MENUSELECT_AGIS=agi-test.agi eagi-test eagi-sphinx-test jukebox.agi" >> ${WRKSRC}/pkgsrc.makeopts
	# this is a hack to work around a bug in menuselect
	cd ${WRKSRC} && make menuselect.makeopts

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

.if !empty(PKG_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
CONFIGURE_ARGS+=	--with-speex
CONFIGURE_ARGS+=	--with-speexdsp
PLIST.speex=		yes
.else
CONFIGURE_ARGS+=	--without-speex
CONFIGURE_ARGS+=	--without-speexdsp
.endif
