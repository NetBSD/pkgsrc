# $NetBSD: Makefile,v 1.1.1.1 2001/02/10 04:36:52 jtb Exp $

DISTNAME=		ratfor77
PKGNAME=		ratfor-1.0
CATEGORIES=		devel
MASTER_SITES=		ftp://sepftp.stanford.edu/pub/sep-distr/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://sepwww.stanford.edu/software/ratfor.html

ALL_TARGET=		ratfor77
USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${PREFIX}/bin/ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.man ${PREFIX}/man/man1/ratfor.1

.include "../../mk/bsd.pkg.mk"
