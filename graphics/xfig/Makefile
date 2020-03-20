# $NetBSD: Makefile,v 1.76 2020/03/20 11:57:53 nia Exp $

DISTNAME=	xfig-3.2.6a
PKGNAME=	${DISTNAME:S/-full//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mcj.sourceforge.net/
COMMENT=	CAD-like 2D drawing tool, good for colorful scale drawings & ISOs

DEPENDS+=	fig2dev-[0-9]*:../../print/fig2dev

XAW_TYPE?=		3d

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
# if we're using Xaw3d, then we need 1.5E or newer since using that
# version means we need a patch, which is currently used unconditionally
BUILDLINK_API_DEPENDS.Xaw3d+=	Xaw3d>=1.5E
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
