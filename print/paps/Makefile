# $NetBSD: Makefile,v 1.22 2020/01/18 23:33:29 rillig Exp $
#

DISTNAME=	paps-0.6.8
PKGREVISION=	19
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paps/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://paps.sourceforge.net/
COMMENT=	Pango to PostScript converter
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/pango/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
