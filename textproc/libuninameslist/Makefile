# $NetBSD: Makefile,v 1.2 2020/09/09 07:41:26 wiz Exp $

DISTNAME=	libuninameslist-dist-20200413
PKGNAME=	${DISTNAME:S/-dist//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fontforge/}
GITHUB_PROJECT=	libuninameslist
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fontforge/libuninameslist
COMMENT=	Library of Unicode names and annotation data
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
