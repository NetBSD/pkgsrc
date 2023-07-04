# $NetBSD: Makefile,v 1.2 2023/07/04 02:29:15 schmonz Exp $

DISTNAME=		pikchr
PKGVERSION=		1.0.20230526
FOSSIL_TAG=		6d40a5f041311bbe
PKGNAME=		${DISTNAME}-${PKGVERSION}
CATEGORIES=		graphics textproc
MASTER_SITES=		https://pikchr.org/home/tarball/${FOSSIL_TAG}/
DIST_SUBDIR=		${PKGBASE}-${FOSSIL_TAG}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://pikchr.org/
COMMENT=		PIC-like markup language for diagrams
LICENSE=		0-clause-bsd

WRKSRC=			${WRKDIR}/${PKGBASE}

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
