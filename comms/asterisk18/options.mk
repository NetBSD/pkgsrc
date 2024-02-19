# $NetBSD: options.mk,v 1.16 2024/02/19 05:59:51 jnemeth Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=		unixodbc ilbc webvmail ldap spandsp
PKG_SUPPORTED_OPTIONS+=		jabber speex snmp pgsql asterisk-config
PKG_SUGGESTED_OPTIONS=		ldap jabber speex asterisk-config

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		zaptel x11 unixodbc webvmail ldap spandsp jabber
PLIST_VARS+=		speex snmp pgsql srtp

# Asterisk now uses DAHDI, not zaptel; not implemented yet...
#.if !empty(PKG_OPTIONS:Mzaptel)
## zaptel only supported under NetBSD at the moment
#.  include "../../comms/zaptel-netbsd/buildlink3.mk"
#PLIST.zaptel=		yes
#.else
#MAKE_FLAGS+=		WITHOUT_ZAPTEL=1
#.endif

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

MAKE_FLAGS+=	GLOBAL_MAKEOPTS=${WRKSRC}/pkgsrc.makeopts
post-configure:
.if !empty(PKG_OPTIONS:Munixodbc)
	${ECHO} "MENUSELECT_OPTS_app_voicemail=ODBC_STORAGE" >> ${WRKSRC}/pkgsrc.makeopts
.endif
#.if defined(PLIST.mgcp)
#	${ECHO} "MENUSELECT_RES=-res_pktccops" >> ${WRKSRC}/pkgsrc.makeopts
#	${ECHO} "MENUSELECT_CHANNELS=-chan_mgcp" >> ${WRKSRC}/pkgsrc.makeopts
#.endif
	${ECHO} "MENUSELECT_AGIS=agi-test.agi eagi-test eagi-sphinx-test jukebox.agi" >> ${WRKSRC}/pkgsrc.makeopts
	${ECHO} "MENUSELECT_CFLAGS=-BUILD_NATIVE" >> ${WRKSRC}/pkgsrc.makeopts
	${ECHO} "MENUSELECT_RES=-res_mwi_external_ami -res_ari_mailboxes -res_pjsip_geolocation -res_stasis_mailbox" >> ${WRKSRC}/pkgsrc.makeopts
	# this is a hack to work around a bug in menuselect
	cd ${WRKSRC} && make menuselect.makeopts

.if !empty(PKG_OPTIONS:Mwebvmail)
DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI
SUBST_CLASSES+=		webvmail
SUBST_STAGE.webvmail=	pre-configure
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
