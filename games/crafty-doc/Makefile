# $NetBSD: Makefile,v 1.5 2003/07/17 21:38:13 grant Exp $

DISTNAME=		crafty-doc-18.0
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/v18/
DISTFILES=		crafty.doc.ps

MAINTAINER=		jlam@NetBSD.org
COMMENT=		documentation for Crafty chess engine

DIST_SUBDIR=		${PKGNAME}
EXTRACT_ONLY=		# empty
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

DOCDIR=			${PREFIX}/share/doc/crafty

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
