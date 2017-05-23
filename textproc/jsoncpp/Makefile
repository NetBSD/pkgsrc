# $NetBSD: Makefile,v 1.7 2017/05/23 12:35:11 mef Exp $

DISTNAME=	jsoncpp-1.8.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-source-parsers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/open-source-parsers/jsoncpp
COMMENT=	JSON reader and writer in C++
LICENSE=	public-domain OR mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	pkg-config/jsoncpp.pc.in

.include "../../mk/bsd.pkg.mk"
