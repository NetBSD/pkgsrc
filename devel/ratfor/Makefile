# $NetBSD: Makefile,v 1.15 2012/10/31 11:19:38 asau Exp $

DISTNAME=		ratfor77
PKGNAME=		ratfor-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://sepwww.stanford.edu/ftp/sep-distr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sepwww.stanford.edu/software/ratfor.html
COMMENT=		Preprocessor for the Ratfor dialect of Fortran

BUILD_TARGET=		ratfor77
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ratfor77 ${DESTDIR}${PREFIX}/bin/ratfor
	${INSTALL_MAN} ${WRKSRC}/ratfor.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ratfor.1

.include "../../mk/bsd.pkg.mk"
