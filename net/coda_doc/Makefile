# $NetBSD: Makefile,v 1.6 2001/02/17 18:18:43 wiz Exp $
#

DISTNAME=	coda-doc-4.6.5-3
PKGNAME=	coda-doc-4.6.5.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	documentation for a replicated, high-performance network file system

#NO_DEPENDS=
#NO_CONFIGURE=

do-build:
	@${ECHO} "At present, Coda documentation is distributed in html,"
	@${ECHO} "man, ps, and ppt forms but documentation source is not"
	@${ECHO} "available.  It should appear in a release or two."

do-install:
	cd ${WRKSRC}; ${PAX} -r -w man ${PREFIX}
	cd ${WRKSRC}; ${PAX} -r -w doc ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
