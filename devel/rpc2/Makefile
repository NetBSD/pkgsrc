# $NetBSD: Makefile,v 1.1.1.1 2000/07/27 18:08:08 phil Exp $
#

DISTNAME=	rpc2-1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	lwp>=1.1:../../devel/lwp

#LICENSE=	GPL

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GMAKE=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
