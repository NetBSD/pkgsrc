# $NetBSD: Makefile,v 1.26 2004/05/28 22:31:50 xtraeme Exp $
#

DISTNAME=	jikes-1.21
CATEGORIES=	lang java
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/1.21/
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
