# $NetBSD: Makefile,v 1.2 2000/08/22 19:08:17 dmcmahill Exp $
#

DISTNAME=	rpc2-1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	lwp>=1.1:../../devel/lwp
DEPENDS+=	readline>=4.0:../../devel/readline

#LICENSE=	GPL

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GMAKE=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
