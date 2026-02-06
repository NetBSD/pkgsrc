# $NetBSD: Makefile,v 1.35 2026/02/06 10:05:27 wiz Exp $

DISTNAME=	nostt-1.3
PKGREVISION=	12
CATEGORIES=	multimedia
MASTER_SITES=	https://codeberg.org/sjmulder/nostt/releases/download/${PKGVERSION_NOREV}/
# remove on next update
DIST_SUBDIR=	nostt-1.3-codeberg

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://codeberg.org/sjmulder/nostt/
COMMENT=	Command line NOS Teletekst reader
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
