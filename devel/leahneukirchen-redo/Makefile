# $NetBSD: Makefile,v 1.1 2020/07/06 15:27:19 schmonz Exp $

GITHUB_PROJECT=		redo-c
GITHUB_TAG=		v0.2
DISTNAME=		v0.2
PKGNAME=		leahneukirchen-redo-${DISTNAME:S,^v,,}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=leahneukirchen/}
DIST_SUBDIR=		${GITHUB_PROJECT}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/leahneukirchen/redo-c/
COMMENT=		Redo build system implemented in portable C
LICENSE=		public-domain

WRKSRC=			${WRKDIR}/redo-c-0.2

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-build:
	cd ${WRKSRC}; \
	cc -Wall -Wextra -Wwrite-strings -o redo redo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/redo ${DESTDIR}${PREFIX}/bin
	cd ${DESTDIR}${PREFIX}/bin; sh ${WRKSRC}/links.do; \
	for i in *; do mv $${i} leahneukirchen-$${i}; done
	${INSTALL_DATA} ${WRKSRC}/NOTES ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
