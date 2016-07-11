# $NetBSD: Makefile,v 1.1 2016/07/11 05:21:59 agc Exp $

DISTNAME=	kilo-20160710
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=antirez/}
GITHUB_TAG=	62b099af00b542bdb08471058d527af258a349cf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://troydhanson.github.io/uthash/
COMMENT=	Small text editor in less than 1K LOC
LICENSE=	2-clause-bsd

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kilo ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
