# $NetBSD: Makefile,v 1.3 2001/04/14 21:43:42 jtb Exp $

DISTNAME=		ratfor77
PKGNAME=		ratfor-1.0
CATEGORIES=		devel
MASTER_SITES=		ftp://sepftp.stanford.edu/pub/sep-distr/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://sepwww.stanford.edu/software/ratfor.html
COMMENT=		Preprocessor for the Ratfor dialect of Fortran

ALL_TARGET=		ratfor77
USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${PREFIX}/bin/ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.man ${PREFIX}/man/man1/ratfor.1

.include "../../mk/bsd.pkg.mk"
