# $NetBSD: Makefile,v 1.10 1998/06/18 16:15:10 agc Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:39 max Exp 
#

DISTNAME=       gsm-1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	packages@netbsd.org

MAKE_FLAGS=	PREFIX="${PREFIX}"

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10

post-install:
	@strip ${PREFIX}/bin/toast
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
