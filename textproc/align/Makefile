# $NetBSD: Makefile,v 1.6 2025/12/17 23:01:19 wiz Exp $

DISTNAME=	align-1.1.1
CATEGORIES=	textproc
MASTER_SITES=	https://codeberg.org/sjmulder/align/releases/download/${PKGVERSION_NOREV}/
# remove on next update
DIST_SUBDIR=	align-1.1.1-codeberg

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://codeberg.org/sjmulder/align
COMMENT=	Center or right-align text files
LICENSE=	2-clause-bsd

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
