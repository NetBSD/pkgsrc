# $NetBSD: Makefile,v 1.6 2001/02/17 18:18:43 wiz Exp $
#

DISTNAME=	coda-intro-4.6.6
PKGNAME=	coda-intro-4.6.6.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	introduction to a replicated, high-performance network file system

do-build:
	@${TRUE}

do-install:
	cd ${WRKSRC}; ${PAX} -r -w -s '|.*CVS||' -s '|.*\.FreeBSD||' \
		doc ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
