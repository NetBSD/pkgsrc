# $NetBSD: Makefile,v 1.2 2020/03/18 17:45:25 joerg Exp $

DISTNAME=	veriwell-2.8.7
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=veriwell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/veriwell/
COMMENT=	Verilog Simulator
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03

TEST_TARGET=	check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
