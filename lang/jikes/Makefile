# $NetBSD: Makefile,v 1.8 2002/02/24 22:07:00 jlam Exp $
#

DISTNAME=	jikes-1.15
CATEGORIES=	lang
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/
COMMENT=	Java source to byte-code compiler

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-*

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CXXFLAGS+=		${CFLAGS}

USE_GMAKE=	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
