# $NetBSD: Makefile,v 1.17 2003/07/17 21:44:43 grant Exp $
#

DISTNAME=	jikes-1.18
CATEGORIES=	lang
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/1.18/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/
COMMENT=	Java source to byte-code compiler

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-* Linux-*-*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GCC_SHLIB=		yes
UNLIMIT_RESOURCES=      datasize

USE_GMAKE=	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
