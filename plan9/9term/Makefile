# $NetBSD: Makefile,v 1.11 1998/06/22 13:01:52 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1996/12/07 23:43:56 asami Exp
#

DISTNAME=       9term.1.6.3
PKGNAME=	9term-1.6.3
CATEGORIES=	plan9
MASTER_SITES=   ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	packages@netbsd.org

# needs library and private header, but not during runtime
BUILD_DEPENDS=	${PKGSRCDIR}/plan9/sam/${WRKDIR:T}/libframe/libframe.a:../../plan9/sam

OPSYS!= 	uname -s
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=	yes
.endif

NO_WRKSUBDIR=	yes
MAKE_ENV+=	WRKDIR=${WRKDIR} PKGSRCDIR=${PKGSRCDIR}

.include "../../mk/bsd.pkg.mk"
