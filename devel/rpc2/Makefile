# $NetBSD: Makefile,v 1.16 2004/02/14 17:21:39 jlam Exp $
#

DISTNAME=	rpc2-1.19
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PERL=${PERL5}

USE_PERL5=		build
USE_LIBTOOL=		YES

.include "../../devel/lwp/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
