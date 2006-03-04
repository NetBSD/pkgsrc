# $NetBSD: Makefile,v 1.11 2006/03/04 21:29:29 jlam Exp $

DISTNAME=		ratfor77
PKGNAME=		ratfor-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://sepftp.stanford.edu/pub/sep-distr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sepwww.stanford.edu/software/ratfor.html
COMMENT=		Preprocessor for the Ratfor dialect of Fortran

BUILD_TARGET=		ratfor77
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${PREFIX}/bin/ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.man ${PREFIX}/man/man1/ratfor.1

.include "../../mk/bsd.pkg.mk"
