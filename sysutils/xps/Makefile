# $NetBSD: Makefile,v 1.53 2022/06/28 11:36:07 wiz Exp $

DISTNAME=	xps-4.2
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif-pstree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://motif-pstree.sourceforge.net/
COMMENT=	Displays the Unix process list as a hierarchical tree

USE_TOOLS+=		gmake perl pod2man pod2html
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	x_applibdir=${PREFIX}/lib/X11/app-defaults

CFLAGS.NetBSD+=	-D_KMEMUSER

# os.c: In function 'GetStatus':
# os.c:176:34: error: array subscript has type 'char' [-Werror=char-subscripts]
#    EndNode->color = base.nodeColor[pstat];
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

post-extract:
	${LN} -s FreeBSD ${WRKSRC}/src/DragonFly

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
