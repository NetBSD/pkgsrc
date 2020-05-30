# $NetBSD: Makefile,v 1.78 2020/05/30 18:11:22 he Exp $

DISTNAME=	xfig-3.2.7b
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mcj.sourceforge.net/
COMMENT=	CAD-like 2D drawing tool, good for colorful scale drawings & ISOs
# not completely, but near enough
LICENSE=	mit

DEPENDS+=	fig2dev-[0-9]*:../../print/fig2dev

XAW_TYPE?=		3d

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-appdefaultdir=${PREFIX}/lib/X11/app-defaults

# w_cmdpanel.c: In function 'change_orient':
# w_cmdpanel.c:893:36: error: array subscript has type 'char' [-Werror=char-subscripts]
#      FirstArg(XtNlabel, orient_items[appres.landscape]);
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
# if we're using Xaw3d, then we need 1.5E or newer since using that
# version means we need a patch, which is currently used unconditionally
BUILDLINK_API_DEPENDS.Xaw3d+=	Xaw3d>=1.5E
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
