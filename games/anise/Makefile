# $NetBSD: Makefile,v 1.1.1.1 2004/07/25 16:13:33 minskim Exp $
#

DISTNAME=	anise-beta10-20040307-linux
PKGNAME=	anise-0beta10
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
