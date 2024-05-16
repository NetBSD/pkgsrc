# $NetBSD: Makefile,v 1.24 2024/05/16 06:15:14 wiz Exp $

DISTNAME=	nostt-1.3
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=sjmulder/}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/sjmulder/nostt/
COMMENT=	Command line NOS Teletekst reader
LICENSE=	2-clause-bsd

INSTALL_MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../www/curl/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
