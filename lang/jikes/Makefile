# $NetBSD: Makefile,v 1.20 2004/01/24 13:51:14 grant Exp $
#

DISTNAME=	jikes-1.18
CATEGORIES=	lang java
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/1.18/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/
COMMENT=	Java source to byte-code compiler

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* SunOS-*-* Linux-*-*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GCC_SHLIB=		yes
UNLIMIT_RESOURCES=      datasize

USE_GNU_TOOLS+=	make	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
