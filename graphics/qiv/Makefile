# $NetBSD: Makefile,v 1.35.2.1 2012/10/03 12:08:12 spz Exp $

DISTNAME=	qiv-2.2.3
PKGREVISION=	11
CATEGORIES=	graphics x11
MASTER_SITES=	http://spiegl.de/qiv/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://spiegl.de/qiv/
COMMENT=	Quick Image Viewer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake pkg-config

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/qiv

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
