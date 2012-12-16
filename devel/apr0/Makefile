# $NetBSD: Makefile,v 1.9 2012/12/16 01:52:09 obache Exp $

.include "../../www/apache2/Makefile.common"

PKGNAME=	apr-${APR_VERSION}.${APACHE_VERSION}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime
LICENSE=	apache-2.0

# Don't bump this when apache upgrades; it is only apache2-2.0.45 and
# under that includes its own apr.  apr was split out in 2.0.45nb1.
CONFLICTS=		apache2<=2.0.45

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/srclib
BUILD_DIRS=		apr apr-util

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIBS=${LIBS:M*:Q}
LIBS.SunOS+=		-lnsl

INSTALLATION_DIRS+=	include/apr-0/arch/unix

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
SUBST_MESSAGE.conf=	Fixing hardcoded paths.

.if !empty(MACHINE_PLATFORM:MDarwin-9.*-*)
APR_CONFIGURE_ARGS+=	--without-sendfile
.endif

TEST_TARGET=		check

do-configure:
	cd ${WRKSRC}/apr && ${SETENV} ${CONFIGURE_ENV} ./configure \
		${APR_CONFIGURE_ARGS}
	cd ${WRKSRC}/apr-util && ${SETENV} ${CONFIGURE_ENV} ./configure \
		${APU_CONFIGURE_ARGS}

post-install:
	${RM} ${DESTDIR}${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} ${DESTDIR}${PREFIX}/libexec/apr/libtool
	${INSTALL_DATA} ${WRKSRC}/apr/include/arch/*.h ${DESTDIR}${PREFIX}/include/apr-0/arch
	${INSTALL_DATA} ${WRKSRC}/apr/include/arch/unix/*.h ${DESTDIR}${PREFIX}/include/apr-0/arch/unix/
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/include/apr-0/*.h
	${CHMOD} ${PKGDIRMODE} ${DESTDIR}${PREFIX}/include/apr-0
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/include/apr-0/

.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
