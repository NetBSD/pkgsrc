# $NetBSD: Makefile,v 1.12 2021/12/08 16:02:12 adam Exp $

DISTNAME=	liblqr-1-0.4.2
PKGNAME=	${DISTNAME:S/-1-/-/}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://liblqr.wikidot.com/local--files/en:download-page/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://liblqr.wikidot.com/
COMMENT=	Content-aware image resizing library
# examples are GPL, library is LGPL, AFAICT
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	lqr-1.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
