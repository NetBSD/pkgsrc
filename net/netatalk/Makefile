# $NetBSD: Makefile,v 1.68 2010/01/30 17:50:03 schwarz Exp $

DISTNAME=	netatalk-2.0.5
PKGREVISION=	1
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netatalk/}
EXTRACT_SUFX=	.tar.bz2
PATCHFILES=	patch-adv1tov2.c
PATCH_SITES=	http://svn.macosforge.org/repository/macports/trunk/dports/net/netatalk/files/ \
		http://mirror.lug.udel.edu/pub/macports/trunk/dports/net/netatalk/files/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://netatalk.sourceforge.net/
COMMENT=	Netatalk appletalk file and print services
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--enable-netbsd \
			--enable-overwrite \
			--enable-timelord \
			--libexecdir=${PREFIX}/libexec/netatalk \
			--sbindir=${PREFIX}/libexec/netatalk \
			--with-pkgconfdir=${PKG_SYSCONFDIR} \
			--with-message-dir=${PKG_SYSCONFDIR}/msg \
			--localstatedir=${VARBASE}/netatalk \
			--with-uams-path=${PREFIX}/libexec/netatalk/uams \
			--with-bdb=${BUILDLINK_PREFIX.db4} \
			--with-ssl-dir=${BUILDLINK_PREFIX.openssl}

MAKE_DIRS+=		${PKG_SYSCONFDIR}/msg

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	etc/psf/etc2ps.sh distrib/initscripts/Makefile.in
SUBST_SED.paths=	-e "s,^\\(DVIPS=\\)\\(/usr/local/tex\\)\\(/bin\\),\\1${PREFIX}\\3,"

RCD_SCRIPTS=		afpd atalkd papd timelord cnid_metad
.for f in ${RCD_SCRIPTS}
RCD_SCRIPT_SRC.${f}=	${WRKSRC}/distrib/initscripts/${f}
.endfor

SUBST_CLASSES+=		rc
SUBST_FILES.rc=		${WRKSRC}/bin/afile/acleandir.rc
SUBST_SED.rc+=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.rc=		pre-configure

.include "options.mk"

INSTALLATION_DIRS=	libexec/psffilters

.if !empty(PKG_OPTIONS:Mpam)
post-install:
	${INSTALL_DATA} ${WRKSRC}/config/netatalk.pamd ${DESTDIR}${EG_DIR}
.endif

.include "../../databases/db4/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
