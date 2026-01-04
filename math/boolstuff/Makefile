# $NetBSD: Makefile,v 1.7 2026/01/04 11:30:47 wiz Exp $

DISTNAME=	boolstuff-0.1.16
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://perso.b2b2c.ca/~sarrazip/dev/boolstuff.html
COMMENT=	Disjunctive Normal Form boolean expression C++ library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
TOOLS_BROKEN+=	perl

PKGCONFIG_OVERRIDE+=	boolstuff-0.1.pc.in

# BoolExprParser.cpp:145:35: error: ISO C++17 does not allow dynamic exception specifications
FORCE_CXX_STD=	c++11

.include "../../mk/bsd.pkg.mk"
