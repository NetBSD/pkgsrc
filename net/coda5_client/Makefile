# $NetBSD: Makefile,v 1.19 1999/10/19 00:28:39 rvb Exp $
#

DISTNAME=		coda-5.3.2
PKGNAME=		coda-client-5.3.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rvb@cs.cmu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/

DEPENDS+=		gdbm-1.7.3:../../databases/gdbm
DEPENDS+=		readline-4.0:../../devel/readline
DEPENDS+=		ncurses-4.2:../../devel/ncurses

ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-ns32k

#LICENSE=		GPL

ALL_TARGET=		coda
INSTALL_TARGET=		client-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
