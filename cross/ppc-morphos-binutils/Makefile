# $NetBSD: Makefile,v 1.13 2026/06/29 20:03:38 js Exp $

DISTNAME=	binutils-2.45.1
PKGREVISION=	1
PKGNAME=	ppc-morphos-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://www.morphos-team.net/
COMMENT=	Binutils for ppc-morphos
LICENSE=	gnu-gpl-v3

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
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS} -DMORPHOS_TARGET -DMORPHOS_SDK_RELEASE_ID=1"

pre-patch:
	${RUN} cd ${WRKSRC} && ${PATCH} -p1 <${FILESDIR}/binutils-2.45.1-morphos.diff

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RUN} rm -f ${DESTDIR}${PREFIX}/gg/share/info/dir

.include "../../mk/bsd.pkg.mk"
