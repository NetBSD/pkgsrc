# $NetBSD: Makefile,v 1.6 1998/04/15 10:38:44 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1996/12/07 23:43:56 asami Exp
#

DISTNAME=       9term.1.6.3
PKGNAME=	9term-1.6.3
CATEGORIES=	plan9
MASTER_SITES=   ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	erich@FreeBSD.org

# needs library and private header, but not during runtime
BUILD_DEPENDS=	${PORTSDIR}/plan9/sam/${WRKDIR:T}/libframe/libframe.a:${PORTSDIR}/plan9/sam

OPSYS!= 	uname -s
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=	yes
.endif

MAN1=		9term.1

NO_WRKSUBDIR=	yes
MAKE_ENV+=	WRKDIR=${WRKDIR}

.include "../../mk/bsd.pkg.mk"
