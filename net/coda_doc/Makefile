# New makefile for:	coda documentation
# Version required:	4.6.5
# Date created:		29 Sept 1998
# Whom:			rvb@cs.cmu.edu
#
# $Id: Makefile,v 1.1.1.1 1998/09/29 20:54:04 rvb Exp $
#

DISTNAME=	coda-doc-4.6.5-3
PKGNAME=	coda-doc-4.6.5-3-pkg
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	coda@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

#NO_DEPENDS=
#NO_CONFIGURE=

do-build:
	@echo At present, Coda documentation is distributed in html, man, ps, and ppt forms
	@echo but documentation source is not available.  It should appear in a release
	@echo or two.

do-install:
	cd ${WRKSRC}; tar cf - man | (cd ${PREFIX}; tar xvf -)
	cd ${WRKSRC}; tar cf - doc | (cd ${PREFIX}/share; tar xvf -)

.include "../../mk/bsd.pkg.mk"
