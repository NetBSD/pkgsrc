# $NetBSD: Makefile,v 1.54 2004/04/10 15:47:08 seb Exp $

GCC_VERSION=	3.3.3
DISTNAME=	gcc3-${GCC_VERSION}
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gcc/gcc.html
COMMENT=	GNU Compiler Collection, v3

NOT_FOR_PLATFORM=	Darwin-*-*

DEPENDS+=	gcc3-c-${GCC_VERSION}{,nb*}:../../lang/gcc3-c
DEPENDS+=	gcc3-c++-${GCC_VERSION}{,nb*}:../../lang/gcc3-c++
DEPENDS+=	gcc3-f77-${GCC_VERSION}{,nb*}:../../lang/gcc3-f77
DEPENDS+=	gcc3-java-${GCC_VERSION}{,nb*}:../../lang/gcc3-java
DEPENDS+=	gcc3-objc-${GCC_VERSION}{,nb*}:../../lang/gcc3-objc

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-patch:	# empty
do-install:	# empty

.include "../../mk/bsd.pkg.mk"
