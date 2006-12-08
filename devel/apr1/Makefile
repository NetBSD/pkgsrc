# $NetBSD: Makefile,v 1.1.1.1 2006/12/08 23:29:53 xtraeme Exp $

.include "../../www/apache22/Makefile.common"

PKGNAME=	apr-${APR_VERSION}
#PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	http://apr.apache.org/
COMMENT=	Apache Portable Runtime

PKG_DESTDIR_SUPPORT=	user-destdir

# Don't bump this when apache upgrades; it is only apache2-2.0.45 and
# under that includes its own apr.  apr was split out in 2.0.45nb1.
CONFLICTS=		apache2<=2.0.45 apr<=0.10

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME}/srclib
BUILD_DIRS=		apr apr-util

CHECK_PORTABILITY_SKIP+=	pcre/*

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LIBS=${LIBS:M*:Q}
LIBS.SunOS+=		-lnsl

PKGCONFIG_OVERRIDE+=	apr-util/apr-util.pc.in
PKGCONFIG_OVERRIDE+=	apr/apr.pc.in

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

TEST_TARGET=		check

do-configure:
	cd ${WRKSRC}/apr && ${SETENV} ${CONFIGURE_ENV} ./configure \
		${APR_CONFIGURE_ARGS}
	cd ${WRKSRC}/apr-util && ${SETENV} ${CONFIGURE_ENV} ./configure \
		${APU_CONFIGURE_ARGS}

post-install:
	${RM} ${DESTDIR}${PREFIX}/libexec/apr/libtool
	${INSTALL_SCRIPT} ${PKG_LIBTOOL} \
		${DESTDIR}${PREFIX}/libexec/apr/libtool
	${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/include/apr-1/arch/unix
	${INSTALL_DATA} ${WRKSRC}/apr/include/arch/*.h \
		${DESTDIR}${PREFIX}/include/apr-1/arch
	${INSTALL_DATA} ${WRKSRC}/apr/include/arch/unix/*.h \
		${DESTDIR}${PREFIX}/include/apr-1/arch/unix/
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/include/apr-1/*.h
	${CHMOD} ${PKGDIRMODE} ${DESTDIR}${PREFIX}/include/apr-1
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/include/apr-1/

	# Create links to be compatible with existing modules
	${LN} -sf ${PREFIX}/bin/apr-1-config ${PREFIX}/bin/apr-config
	${LN} -sf ${PREFIX}/bin/apu-1-config ${PREFIX}/bin/apu-config

.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
