# $NetBSD: Makefile,v 1.23 2020/03/08 16:51:04 wiz Exp $
#

DISTNAME=	paps-0.6.8
PKGREVISION=	20
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
