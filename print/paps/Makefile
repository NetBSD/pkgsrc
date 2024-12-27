# $NetBSD: Makefile,v 1.32 2024/12/27 08:20:33 wiz Exp $
#

DISTNAME=	paps-0.6.8
PKGREVISION=	28
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
