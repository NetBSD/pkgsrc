# $NetBSD: Makefile,v 1.2 2017/12/31 13:22:46 wiz Exp $

DISTNAME=	postsrsd-1.4
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=roehling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/roehling/postsrsd
COMMENT=	Postfix Sender Rewriting Scheme daemon
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	CMakeLists.txt
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../mk/bsd.pkg.mk"
