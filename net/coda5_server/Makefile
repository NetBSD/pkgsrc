# $NetBSD: Makefile,v 1.21 2000/02/09 02:30:36 fredb Exp $
#

DISTNAME=		coda-5.3.5
PKGNAME=		coda-server-5.3.5
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rvb@cs.cmu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/

DEPENDS+=		lwp>=1.1:../../devel/lwp
DEPENDS+=		ncurses>=4.2:../../devel/ncurses
DEPENDS+=		readline-4.0:../../devel/readline

#LICENSE=		GPL

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
