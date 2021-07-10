# $NetBSD: Makefile,v 1.3 2021/07/10 08:41:56 spz Exp $

DISTNAME=	postsrsd-1.11
#PKGREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=roehling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/roehling/postsrsd
COMMENT=	Postfix Sender Rewriting Scheme daemon
LICENSE=	gnu-gpl-v2

RCD_SCRIPTS=	postsrsd

POSTSRSD_USER?=		postsrsd
POSTSRSD_GROUP?=	postsrsd
PKG_USERS=		${POSTSRSD_USER}:${POSTSRSD_GROUP}
PKG_GROUPS=		${POSTSRSD_GROUP}
USER_GROUP=		${POSTSRSD_USER} ${POSTSRSD_GROUP}

PKG_GECOS.${POSTSRSD_USER}?=	postSRSd


USE_CMAKE=	yes
BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	CMakeLists.txt
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../mk/bsd.pkg.mk"
