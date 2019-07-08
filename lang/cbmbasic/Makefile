# $NetBSD: Makefile,v 1.1 2019/07/08 06:46:22 sjmulder Exp $

DISTNAME=	cbmbasic-0.0.20141206
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=mist64/}
GITHUB_TAG=	89093eba090d6e1c2d2b6e1cb1616dba0ce9c7f6

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/mist64/cbmbasic/
COMMENT=	Portable implementation of Commodore BASIC
LICENSE=	2-clause-bsd

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cbmbasic ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
