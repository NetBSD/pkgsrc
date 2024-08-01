# $NetBSD: Makefile,v 1.2 2024/08/01 18:50:46 vins Exp $

DISTNAME=	xmakemol-5.16h
CATEGORIES=	biology x11
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/vins/dists/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/xmakemol/
COMMENT=	Program for visualizing atomic and molecular systems
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
USE_TOOLS+=	autoconf automake autoreconf

REPLACE_PERL=	xmake_anim.pl

ELEM_FILE=	${WRKSRC}/elements

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	xmakemol.1
SUBST_VARS.paths=	PREFIX
SUBST_MESSAGE.paths=	Replacing PREFIX placeholder.

CONFIGURE_ARGS+=	--with-mesa
CONFIGURE_ARGS+=	--with-opengl=${BUILDLINK_PREFIX.MesaLib}

BUILDLINK_TRANSFORM+=	l:MesaGL:GL
BUILDLINK_TRANSFORM+=	l:MesaGLU:GLU

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS='${CFLAGS} -DELEMENTS=\"${ELEM_FILE}\"'
MAKE_FLAGS+=	CPPLAGS=${CPPLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS=	share/applications

WRKSRC=	${WRKDIR}/${DISTNAME:S,h,,}

post-extract:
	${CP} ${FILESDIR}/xmakemol.desktop ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/xmakemol.desktop \
		${DESTDIR}${PREFIX}/share/applications/xmakemol.desktop

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glw/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
