# $NetBSD: Makefile,v 1.17 2004/04/27 04:29:17 snj Exp $
#

DISTNAME=	rpc2-1.19
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PERL=${PERL5}

USE_PERL5=		build
USE_LIBTOOL=		YES

.include "../../devel/lwp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
