# $NetBSD: Makefile,v 1.10.2.2 2002/07/01 17:44:57 jlam Exp $
#

DISTNAME=	rpc2-1.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PERL=${PERL5}

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/lwp/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
