# $NetBSD: Makefile,v 1.8 2003/07/21 17:10:30 martti Exp $
#

DISTNAME=	coda-doc-4.6.5-3
PKGNAME=	coda-doc-4.6.5.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Documentation for a replicated, high-performance network file system

#NO_DEPENDS=
#NO_CONFIGURE=

do-build:
	@${ECHO} "At present, Coda documentation is distributed in html,"
	@${ECHO} "man, ps, and ppt forms but documentation source is not"
	@${ECHO} "available.  It should appear in a release or two."

do-install:
	cd ${WRKSRC} && ${PAX} -rw man ${PREFIX}
	cd ${WRKSRC} && ${PAX} -rw doc ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
