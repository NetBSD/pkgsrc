# $NetBSD: Makefile,v 1.11 2002/06/20 19:28:01 jlam Exp $
#

DISTNAME=	rpc2-1.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ENV+=		PERL=${PERL5}

.include "../../devel/lwp/buildlink.mk"
.include "../../devel/readline/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
