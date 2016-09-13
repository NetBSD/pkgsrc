# $NetBSD: Makefile,v 1.2 2016/09/13 20:25:04 agc Exp $

DISTNAME=	kilo-20160710
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=antirez/}
GITHUB_TAG=	62b099af00b542bdb08471058d527af258a349cf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/antirez/kilo
COMMENT=	Small text editor in less than 1K LOC
LICENSE=	2-clause-bsd

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kilo ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
