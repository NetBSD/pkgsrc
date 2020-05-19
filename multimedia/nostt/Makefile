# $NetBSD: Makefile,v 1.12 2020/05/19 12:09:08 nia Exp $

DISTNAME=	nostt-1.2
PKGREVISION=	5
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
