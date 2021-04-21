# $NetBSD: Makefile,v 1.13 2021/04/21 15:40:38 wiz Exp $

DISTNAME=		crafty-doc-18.0
CATEGORIES=		games
#MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/v18/
DISTFILES=		crafty.doc.ps

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Documentation for Crafty chess engine

DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_ONLY=		# empty
NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			${PREFIX}/share/doc/crafty

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for file in ${DISTFILES}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${file} \
			${DESTDIR}${DOCDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
