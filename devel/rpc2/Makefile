# $NetBSD: Makefile,v 1.3 2000/08/25 01:30:47 wiz Exp $
#

DISTNAME=	rpc2-1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/

DEPENDS+=	lwp>=1.1:../../devel/lwp
DEPENDS+=	readline>=4.0:../../devel/readline

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GMAKE=	YES
USE_PERL5=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
