# $NetBSD: Makefile,v 1.7 2001/06/10 00:08:43 jlam Exp $
#

DISTNAME=	rpc2-1.10
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	CMU (Coda) remote procedure call package

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_GMAKE=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../devel/lwp/buildlink.mk"
.include "../../devel/readline/buildlink.mk"

CONFIGURE_ENV+=	ac_cv_search_tgetent="-ltermcap"
CONFIGURE_ENV+=	PERL=${PERL5}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${BUILDLINK_INCDIR}
LDFLAGS+=	-L${BUILDLINK_LIBDIR}

.include "../../mk/bsd.pkg.mk"
