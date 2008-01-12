# $NetBSD: Makefile,v 1.55 2008/01/12 11:36:33 adam Exp $

DISTNAME=	netatalk-2.0.3
PKGREVISION=	7
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://netatalk.sourceforge.net/
COMMENT=	Netatalk appletalk file and print services

DEPENDS=	rc>=1.5:../../shells/rc

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake perl:run
USE_LIBTOOL=	YES
USE_OLD_DES_API=YES
BUILDLINK_TRANSFORM+=	l:db-4.2:db4

PKG_SYSCONFSUBDIR=	netatalk
EG_DIR=		${PREFIX}/share/examples/netatalk
CONF_FILES=	${EG_DIR}/AppleVolumes.default ${PKG_SYSCONFDIR}/AppleVolumes.default \
		${EG_DIR}/AppleVolumes.system ${PKG_SYSCONFDIR}/AppleVolumes.system \
		${EG_DIR}/afpd.conf ${PKG_SYSCONFDIR}/afpd.conf \
		${EG_DIR}/atalkd.conf ${PKG_SYSCONFDIR}/atalkd.conf \
		${EG_DIR}/netatalk.conf ${PKG_SYSCONFDIR}/netatalk.conf \
		${EG_DIR}/papd.conf ${PKG_SYSCONFDIR}/papd.conf

CONFLICTS=	netatalk-asun-[0-9]* netatalk-umich-[0-9]*

RCD_SCRIPTS=	atalkd afpd papd timelord
RCD_SCRIPT_SRC.atalkd=		# empty
RCD_SCRIPT_SRC.afpd=		# empty
RCD_SCRIPT_SRC.papd=		# empty
RCD_SCRIPT_SRC.timelord=	# empty

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-netbsd \
			--enable-overwrite \
			--enable-timelord \
			--libexecdir=${PREFIX}/libexec/netatalk \
			--sbindir=${PREFIX}/libexec/netatalk \
			--with-pkgconfdir=${PKG_SYSCONFDIR:Q} \
			--with-message-dir=${PKG_SYSCONFDIR}/msg \
			--localstatedir=${VARBASE}/netatalk \
			--with-uams-path=${PREFIX}/libexec/netatalk/uams \
			--with-bdb=${BUILDLINK_PREFIX.db4} \
			--with-ssl-dir=${BUILDLINK_PREFIX.openssl}

MAKE_DIRS+=		${PKG_SYSCONFDIR}/msg

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	etc/psf/etc2ps.sh distrib/initscripts/Makefile.in
SUBST_SED.paths=	-e "s,^\(DVIPS=\)\(/usr/local/tex\)\(/bin\),\1${PREFIX}\3,"
SUBST_SED.paths+=	-e "s,\(NETBSD.*\)/etc/rc.d,\1${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR},"

SUBST_CLASSES+=		rc
SUBST_FILES.rc=		${WRKSRC}/bin/afile/acleandir.rc
SUBST_SED.rc+=		-e 's,@PREFIX@,${PREFIX:Q},g'
SUBST_STAGE.rc=		pre-configure

PKG_OPTIONS_VAR=	PKG_OPTIONS.netatalk
PKG_SUPPORTED_OPTIONS=	cups kerberos pam slp

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cups
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-gssapi --enable-krbV-uam
CONFIGURE_ENV+=	GSSAPI_LIBS="-lkrb5 -lroken -lasn1 -lcrypto -lcom_err"
PLIST_SUBST+=		GSSAPI=""
.else
CONFIGURE_ARGS+=	--without-gssapi
PLIST_SUBST+=		GSSAPI="@comment "
.endif

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
PLIST_SUBST+=		PAM=""
MESSAGE_SRC+=		MESSAGE MESSAGE.pam
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUBST+=		PAM="@comment "
.endif

.if !empty(PKG_OPTIONS:Mslp)
.include "../../net/openslp/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-srvloc
.else
CONFIGURE_ARGS+=	--disable-srvloc
.endif

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/psffilters

.if !empty(PKG_OPTIONS:Mpam)
post-install:
	${INSTALL_DATA} ${WRKSRC}/config/netatalk.pamd ${EG_DIR}
.endif

.include "../../databases/db4/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
