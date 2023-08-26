# $NetBSD: Makefile,v 1.5 2023/08/26 11:27:42 vins Exp $

DISTNAME=	outils-0.12
PKGREVISION=	1
PKGNAME=	${DISTNAME:S,outils,signify,}
CATEGORIES=	security
MASTER_SITES=	https://git.vuxu.org/outils/snapshot/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://flak.tedunangst.com/post/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	original-bsd AND modified-bsd AND isc AND public-domain

USE_TOOLS+=	gmake

LIBS+=		-lm
LIBS.SunOS+=	-lresolv -lrt

MAKE_FLAGS+=	ALL=src/usr.bin/signify/signify
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	LIBS=${LIBS:Q}

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKE_DIRS+=		${PKG_SYSCONFDIR}/signify

OUTDIR:=	${WRKSRC}/src/usr.bin/signify
LIBSRCDIR:=	${WRKSRC}/src/liboutils

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Do not hardcode configuration directory
SUBST_FILES.paths+=	${OUTDIR}/signify.c
SUBST_FILES.paths+=	${OUTDIR}/signify.1
SUBST_SED.paths=	-e 's|/etc/signify|${PKG_SYSCONFDIR}/signify|g'

.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		ints
SUBST_MESSAGE.ints=	SunOS stdint(3) doesn't provide `u_int*' typedefs
SUBST_STAGE.ints=	pre-configure
SUBST_FILES.ints+=	${LIBSRCDIR}/*.c
SUBST_FILES.ints+=	${LIBSRCDIR}/include/*.h
SUBST_SED.ints=		-e 's|u_int|uint|g'
.endif

post-patch:
.if ${OPSYS} == "NetBSD"
# The sys/* overrides are not needed on NetSD
	${RM} ${WRKSRC}/src/liboutils/include/sys/*

.elif ${OPSYS} == "SunOS"
# Solaris lacks MIN/MAX macros in sys/param.h
	cd ${LIBSRCDIR} && ${CP} ${FILESDIR}/minmax.h . 					\
	&& ${CAT} outils.h >> minmax.h && ${MV} minmax.h outils.h
.endif

do-install:
	${INSTALL_PROGRAM} ${OUTDIR}/signify ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${OUTDIR}/signify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
