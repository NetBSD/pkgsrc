# $NetBSD: Makefile,v 1.2 2001/02/16 14:38:59 wiz Exp $

DISTNAME=		ratfor77
PKGNAME=		ratfor-1.0
CATEGORIES=		devel
MASTER_SITES=		ftp://sepftp.stanford.edu/pub/sep-distr/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://sepwww.stanford.edu/software/ratfor.html
COMMENT=		Preprocessor for the Ratfor dialect of Fortran

ALL_TARGET=		ratfor77
USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${PREFIX}/bin/ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.man ${PREFIX}/man/man1/ratfor.1

.include "../../mk/bsd.pkg.mk"
