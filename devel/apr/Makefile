# $NetBSD: Makefile,v 1.31 2005/02/09 14:52:12 tron Exp $

.include "../../www/apache2/Makefile.common"

PKGNAME=	apr-${APR_VERSION}.${APACHE_VERSION}
CATEGORIES=	devel

HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime

# Don't bump this when apache upgrades; it is only apache2-2.0.45 and
# under that includes its own apr.  apr was split out in 2.0.45nb1.
CONFLICTS=		apache2<=2.0.45

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

WRKSRC=			${WRKDIR}/${DISTNAME}/srclib
BUILD_DIRS=		${WRKSRC}/apr ${WRKSRC}/apr-util

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LIBS="${LIBS}"
LIBS.SunOS+=		-lnsl

APR_CONFIGURE_ARGS= \
		--prefix=${PREFIX} \
		--with-devrandom=/dev/urandom \
		--with-installbuilddir=${PREFIX}/libexec/apr

APU_CONFIGURE_ARGS= \
		--prefix=${PREFIX} \
		--with-apr=${WRKSRC}/apr \
		--with-expat=${BUILDLINK_PREFIX.expat} \
		--without-gdbm

.include "../../mk/bsd.prefs.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "options.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	apr/config.layout apr-util/config.layout
SUBST_SED.conf=		-e "s,@PREFIX@,${PREFIX},g"
SUBST_MESSAGE.conf=	"Fixing harcoded paths."

do-configure:
	@cd ${WRKSRC}/apr && ${SETENV} ${CONFIGURE_ENV} ./configure \
		${APR_CONFIGURE_ARGS}
	@cd ${WRKSRC}/apr-util && ${SETENV} ${CONFIGURE_ENV} ./configure \
		${APU_CONFIGURE_ARGS}

post-install:
	${RM} ${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} ${PREFIX}/libexec/apr/libtool
	@${CHMOD} ${SHAREMODE} ${PREFIX}/include/apr-0/*.h
	@${CHMOD} ${PKGDIRMODE} ${PREFIX}/include/apr-0
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/include/apr-0/

.include "../../mk/bsd.pkg.mk"
