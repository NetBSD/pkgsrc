# $NetBSD: Makefile,v 1.24 2000/07/31 09:09:57 rh Exp $
#

DISTNAME=		coda-5.3.5
PKGNAME=		coda-client-5.3.5
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/

DEPENDS+=		lwp>=1.1:../../devel/lwp
DEPENDS+=		ncurses>=4.2:../../devel/ncurses
DEPENDS+=		readline>=4.0:../../devel/readline

#LICENSE=		GPL

ALL_TARGET=		coda
INSTALL_TARGET=		client-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${WRKSRC}/include"
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS} -I${WRKSRC}/include"

.include "../../mk/bsd.pkg.mk"
