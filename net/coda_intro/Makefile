# $NetBSD: Makefile,v 1.1.1.1 1998/10/02 20:06:34 rvb Exp $
#

DISTNAME=	coda-intro-4.6.5-1
PKGNAME=	coda-intro-4.6.5.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

#NO_DEPENDS=
#NO_CONFIGURE=

do-build:
	@${ECHO} "These are simple text files.  We are copying them to share/doc/coda-doc-.../info"

do-install:
	cd ${WRKSRC}; tar cf - doc | (cd ${PREFIX}/share; tar xvf -)

.include "../../mk/bsd.pkg.mk"
