# $NetBSD: Makefile,v 1.10 2002/09/29 07:36:49 jlam Exp $
#

DISTNAME=	jikes-1.15
CATEGORIES=	lang
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/
COMMENT=	Java source to byte-code compiler

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_CXX=		yes
CXXFLAGS+=		${CFLAGS}
UNLIMIT_RESOURCES=      datasize

USE_GMAKE=	# uses multi-line comments with \ (naughty hack!)

.include "../../lang/gcc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
