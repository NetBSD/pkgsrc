# $NetBSD: Makefile,v 1.27 2004/10/06 02:40:55 tv Exp $
#

DISTNAME=	jikes-1.22
CATEGORIES=	lang java
MASTER_SITES=	http://oss.software.ibm.com/pub/${DISTNAME:S,-,/,}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/
COMMENT=	Java source to byte-code compiler

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_GCC_SHLIB=		yes
UNLIMIT_RESOURCES=      datasize

USE_GNU_TOOLS+=	make	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
