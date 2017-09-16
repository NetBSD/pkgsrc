# $NetBSD: Makefile,v 1.2 2017/09/16 19:26:57 wiz Exp $

GITHUB_RELEASE=	wtfubar-2.5.0
DISTNAME=	${GITHUB_RELEASE}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=othyro/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/othyro/wtfubar
COMMENT=	Fork of NetBSD's wtf
LICENSE=	public-domain

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+= 	bin share/${PKGBASE} ${PKGMANDIR}/man6

.include "../../mk/bsd.pkg.mk"
