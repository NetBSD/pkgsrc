# $NetBSD: Makefile,v 1.7 2001/06/19 03:32:40 jlam Exp $
#

DISTNAME=	rvm-1.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Recoverable Virtual Memory

#LICENSE=	GPL

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--with-lwp-includes=${BUILDLINK_DIR}/include
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/lwp/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
