# $NetBSD: Makefile,v 1.5 2001/04/27 19:02:59 phil Exp $
#

DISTNAME=	rpc2-1.10
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

DEPENDS+=	lwp>=1.6:../../devel/lwp
DEPENDS+=	readline>=4.0:../../devel/readline

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GMAKE=	YES
USE_PERL5=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
