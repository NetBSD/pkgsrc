# $NetBSD: Makefile,v 1.12 1999/09/26 22:06:27 jlam Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:39 max Exp 
#

DISTNAME=       gsm-1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://kbs.cs.tu-berlin.de/~jutta/toast.html

MAKE_FLAGS=	PREFIX="${PREFIX}"

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10

post-install:
	@strip ${PREFIX}/bin/toast

.include "../../mk/bsd.pkg.mk"
