# $NetBSD: Makefile,v 1.5 2000/01/10 00:57:15 wiz Exp $
#

DISTNAME=	coda-intro-4.6.6
PKGNAME=	coda-intro-4.6.6.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

do-build:
	@${TRUE}

do-install:
	cd ${WRKSRC}; ${PAX} -r -w -s '|.*CVS||' -s '|.*\.FreeBSD||' \
		doc ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
