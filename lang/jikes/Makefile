# $NetBSD: Makefile,v 1.4 2000/10/16 20:38:20 tv Exp $
#

DISTNAME=	jikes-1.12
CATEGORIES=	lang
MASTER_SITES=	http://oss.software.ibm.com/developerworks/opensource/jikes/project/pub/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www10.software.ibm.com/developerworks/opensource/jikes/

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-*

CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

GNU_CONFIGURE=	yes

USE_GMAKE=	# uses multi-line comments with \ (naughty hack!)

.include "../../mk/bsd.pkg.mk"
