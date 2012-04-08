# $NetBSD: Makefile,v 1.65.22.1 2012/04/08 09:18:55 sbd Exp $

GCC_VERSION=	3.3.6
DISTNAME=	gcc3-${GCC_VERSION}
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gcc.gnu.org/
COMMENT=	GNU Compiler Collection, v3

NOT_FOR_PLATFORM=	Darwin-*-*

META_PACKAGE=	yes

DEPENDS+=	gcc3-c-${GCC_VERSION}{,nb*}:../../lang/gcc3-c
DEPENDS+=	gcc3-c++-${GCC_VERSION}{,nb*}:../../lang/gcc3-c++
DEPENDS+=	gcc3-f77-${GCC_VERSION}{,nb*}:../../lang/gcc3-f77
# Not buildable for ages and has proved not fixable in practice.
#DEPENDS+=	gcc3-java-${GCC_VERSION}{,nb*}:../../lang/gcc3-java
DEPENDS+=	gcc3-objc-${GCC_VERSION}{,nb*}:../../lang/gcc3-objc

.include "../../mk/bsd.pkg.mk"
