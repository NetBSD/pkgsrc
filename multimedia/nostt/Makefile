# $NetBSD: Makefile,v 1.32 2025/12/17 14:34:37 sjmulder Exp $

DISTNAME=	nostt-1.3
PKGREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	https://codeberg.org/sjmulder/nostt/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://codeberg.org/sjmulder/nostt/
COMMENT=	Command line NOS Teletekst reader
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
