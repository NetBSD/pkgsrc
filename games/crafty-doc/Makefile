# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 02:09:31 jlam Exp $

DISTNAME=		crafty-doc-17.0
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/
DISTFILES=		crafty.doc.ps

MAINTAINER=		jlam@netbsd.org

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
