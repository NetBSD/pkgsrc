# $NetBSD: Makefile,v 1.20 2018/11/12 03:52:49 ryoon Exp $
#

DISTNAME=	paps-0.6.8
PKGREVISION=	18
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://paps.sourceforge.net/
COMMENT=	Pango to PostScript converter
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
