# $NetBSD: Makefile,v 1.6 2001/05/16 10:05:35 agc Exp $
#

DISTNAME=	jikes-1.14
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
