# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:42 tv Exp $
#

DISTNAME=	anise-beta10-20040307-linux
PKGNAME=	anise-0beta10
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://kldp.net/download.php/1051/

MAINTAINER=	pyrasis@chol.com
HOMEPAGE=	http://www.tomyun.pe.kr/projectanise/
COMMENT=	Adventure game scripting engine

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
