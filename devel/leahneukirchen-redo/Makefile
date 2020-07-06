# $NetBSD: Makefile,v 1.2 2020/07/06 16:48:50 schmonz Exp $

DISTNAME=		leahneukirchen-redo-0.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_PROJECT=		redo-c
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/leahneukirchen/redo-c/
COMMENT=		Redo build system implemented in portable C
LICENSE=		public-domain

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

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
