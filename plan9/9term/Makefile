# $NetBSD: Makefile,v 1.17 1999/03/22 09:38:26 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1996/12/07 23:43:56 asami Exp
#

DISTNAME=       9term.1.6.3
PKGNAME=	9term-1.6.3
CATEGORIES=	plan9
MASTER_SITES=   ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.psrg.cs.usyd.edu.au/~matty/9term/index.html

# needs library and private header, but not during runtime
BUILD_DEPENDS=	${BUILD_ROOT}/plan9/sam/${WRKDIR:T}/libframe/libframe.a:../../plan9/sam

NOT_FOR_ARCHS=	alpha	#LP64 Problems

MANCOMPRESSED=	yes
NO_WRKSUBDIR=	yes
MAKE_ENV+=	WRKDIR=${WRKDIR} PKGSRCDIR=${BUILD_ROOT}

.include "../../mk/bsd.pkg.mk"
