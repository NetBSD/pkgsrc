# $NetBSD: Makefile,v 1.10 2020/03/08 16:50:45 wiz Exp $

DISTNAME=	nostt-1.2
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
