# $NetBSD: Makefile,v 1.7 2002/02/12 19:56:51 mjl Exp $
#

DISTNAME=	jikes-1.15
CATEGORIES=	lang
MASTER_SITES=	http://oss.software.ibm.com/pub/jikes/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/
COMMENT=	Java source to byte-code compiler

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-*

CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

GNU_CONFIGURE=	yes

USE_GMAKE=	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
