# $NetBSD: Makefile,v 1.25 2004/04/27 23:23:03 recht Exp $
#

DISTNAME=	jikes-1.20
CATEGORIES=	lang java
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/1.20/
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
