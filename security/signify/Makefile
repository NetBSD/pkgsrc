# $NetBSD: Makefile,v 1.3 2022/11/21 18:20:44 jperkin Exp $

DISTNAME=	outils-0.12
PKGNAME=	${DISTNAME:S,outils,signify,}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_PROJECT=	outils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://flak.tedunangst.com/post/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	original-bsd AND modified-bsd AND isc AND public-domain

USE_TOOLS+=	gmake
MAKE_FLAGS+=	ALL=src/usr.bin/signify/signify
MAKE_FLAGS+=	LIBS=${LIBS:Q}
LIBS+=		-lm

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

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

LIBS.SunOS+=	-lresolv -lrt

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
