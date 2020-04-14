# $NetBSD: Makefile,v 1.1 2020/04/14 20:53:21 js Exp $

DISTNAME=	sdk-source-20191111
PKGNAME=	ppc-morphos-binutils-2.33.1
CATEGORIES=	cross
MASTER_SITES=	https://morphos-team.net/files/src/sdk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	Binutils for ppc-morphos
LICENSE=	gnu-gpl-v3

WRKSRC=			${WRKDIR}/sdk-source/binutils/binutils-${PKGVERSION_NOREV}
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		xzcat gtar patch gmake makeinfo

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

do-patch:
	${RUN} cd ${WRKDIR}/sdk-source/binutils && \
		${PATCH} -p0 <binutils-${PKGVERSION_NOREV}-morphos.diff

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RUN} rm -f ${DESTDIR}${PREFIX}/gg/share/info/dir

.include "../../mk/bsd.pkg.mk"
