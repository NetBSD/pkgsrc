# $NetBSD: Makefile,v 1.1 2021/11/26 09:38:52 schmonz Exp $

DISTNAME=		pikchr
PKGVERSION=		1.0.20211104
FOSSIL_TAG=		b79ce27929e9cc79
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
