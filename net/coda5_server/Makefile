# $NetBSD: Makefile,v 1.18 1999/10/05 00:21:12 hubertf Exp $
#

DISTNAME=		coda-5.2.4
PKGNAME=		coda-server-5.2.4
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rvb@cs.cmu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/

DEPENDS+=		gdbm-1.7.3:../../databases/gdbm
DEPENDS+=		readline-4.0:../../devel/readline
DEPENDS+=		ncurses-4.2:../../devel/ncurses

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-ns32k

#LICENSE=		GPL

ALL_TARGET=		coda
INSTALL_TARGET=		server-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
