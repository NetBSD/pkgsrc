# $NetBSD: options.mk,v 1.19 2023/01/03 16:53:17 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=		x11 unixodbc webvmail ldap spandsp
PKG_SUPPORTED_OPTIONS+=		jabber speex snmp pgsql asterisk-config
PKG_OPTIONS_LEGACY_OPTS+=	gtk:x11
PKG_SUGGESTED_OPTIONS=		speex asterisk-config spandsp

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11 unixodbc webvmail ldap spandsp jabber
PLIST_VARS+=		speex snmp pgsql

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
CONFIGURE_ARGS+=	--with-unixodbc
PLIST.unixodbc=		yes
.else
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

post-configure:
	cd ${WRKSRC} && \
	env ${MAKE_ENV} && \
	    ${MAKE_PROGRAM} menuselect.makeopts
.if !empty(PKG_OPTIONS:Mx11)
	# I have no idea about x11 option's fate.
	#${ECHO} "MENUSELECT_PBX=-pbx_gtkconsole" >> ${WRKSRC}/pkgsrc.makeopts
.endif
.if !empty(PKG_OPTIONS:Munixodbc)
	cd ${WRKSRC} && \
	./menuselect/menuselect --enable ODBC_STORAGE menuselect.makeopts
.endif
.if defined(PLIST.mgcp)
	cd ${WRKSRC} && \
	./menuselect/menuselect --enable res_pktccops menuselect.makeopts
	cd ${WRKSRC} && \
	./menuselect/menuselect --enable chan_mgcp menuselect.makeopts
.else
	cd ${WRKSRC} && \
	./menuselect/menuselect --disable res_pktccops menuselect.makeopts
	cd ${WRKSRC} && \
	./menuselect/menuselect --disable chan_mgcp menuselect.makeopts
.endif
	cd ${WRKSRC} && \
	./menuselect/menuselect --enable agi-test.agi menuselect.makeopts
	cd ${WRKSRC} && \
	./menuselect/menuselect --enable eagi-test menuselect.makeopts
	cd ${WRKSRC} && \
	./menuselect/menuselect --enable eagi-sphinx-test menuselect.makeopts
	cd ${WRKSRC} && \
	./menuselect/menuselect --enable jukebox.agi menuselect.makeopts

.if !empty(PKG_OPTIONS:Mwebvmail)
DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI
SUBST_CLASSES+=		webvmail
SUBST_STAGE.webvmail=	post-patch
SUBST_FILES.webvmail=	contrib/scripts/vmail.cgi
SUBST_VARS.webvmail=	ASTETCDIR
SUBST_VARS.webvmail+=	ASTSPOOLDIR
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
.include "../../audio/speexdsp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-speex
CONFIGURE_ARGS+=	--with-speexdsp
PLIST.speex=		yes
.else
CONFIGURE_ARGS+=	--without-speex
CONFIGURE_ARGS+=	--without-speexdsp
.endif

.if !empty(PKG_OPTIONS:Msnmp)
.include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-netsnmp
PLIST.snmp=		yes
.else
CONFIGURE_ARGS+=	--without-netsnmp
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgres
PLIST.pgsql=		yes
.else
CONFIGURE_ARGS+=	--without-postgres
.endif
