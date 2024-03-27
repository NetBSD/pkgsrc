# $NetBSD: Makefile,v 1.10 2024/03/27 15:52:32 js Exp $

DISTNAME=	sdk-source-20230510
PKGNAME=	ppc-morphos-binutils-2.40
CATEGORIES=	cross
MASTER_SITES=	https://morphos-team.net/files/src/sdk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	Binutils for ppc-morphos
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/sdk-source/binutils/binutils-${PKGVERSION_NOREV}
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls
USE_LANGUAGES=		c c++
USE_TOOLS+=		xzcat gtar patch gmake makeinfo perl

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/gg
CONFIGURE_ARGS+=	--target=ppc-morphos
CONFIGURE_ARGS+=	--enable-plugins=no
CONFIGURE_ARGS+=	--disable-initfini-array
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS} -DMORPHOS_TARGET"

post-extract:
	${RUN} cd ${WRKDIR}/sdk-source/binutils && \
		${XZCAT} binutils-${PKGVERSION_NOREV}.tar.xz | ${GTAR} xf -

pre-patch:
	${RUN} cd ${WRKDIR}/sdk-source/binutils && \
		${PATCH} -p0 <binutils-${PKGVERSION_NOREV}-morphos.diff

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RUN} rm -f ${DESTDIR}${PREFIX}/gg/share/info/dir

.include "../../mk/bsd.pkg.mk"
