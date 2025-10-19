# $NetBSD: Makefile,v 1.8 2025/10/19 20:34:04 vins Exp $

DISTNAME=	signify-20250520
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/vins/dists/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://flak.tedunangst.com/post/signify
COMMENT=	Cryptographically sign and verify files, from OpenBSD
LICENSE=	original-bsd AND modified-bsd AND isc AND public-domain

CFLAGS.Linux+=	-D_GNU_SOURCE		# dl_iterate_phd()
CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t
CFLAGS.SunOS+=	-Du_int32_t=uint32_t -Du_int64_t=uint64_t

LIBS+=		-lm
LIBS.SunOS+=	-lresolv -lrt

USE_BSD_MAKEFILE=	yes

MAKE_ENV+=		EXTRA_SRCS=${BUILD_SRCS:Q} LDADD=${LIBS:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
MAKE_DIRS+=		${PKG_SYSCONFDIR}/signify

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Do not hardcode configuration directory
SUBST_FILES.paths+=	signify.c signify.1
SUBST_SED.paths=	-e 's|/etc/signify|${PKG_SYSCONFDIR}/signify|g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Darwin"
BUILD_SRCS+=	explicit_bzero.c freezero.c
.elif ${OPSYS} == "Linux"
BUILD_SRCS+=	arc4random.c base64.c explicit_bzero.c \
		freezero.c getentropy_linux.c strlcpy.c
.endif

post-patch:
.if ${OPSYS} == "NetBSD"
# The sys/* overrides are not needed on NetBSD
	${RUN}${RM} ${WRKSRC}/incs/sys/*
.endif

.include "../../mk/bsd.pkg.mk"
