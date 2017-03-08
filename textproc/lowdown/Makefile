# $NetBSD: Makefile,v 1.1 2017/03/08 15:05:02 wiz Exp $

DISTNAME=	lowdown-0.1.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}
GITHUB_TAG=	VERSION_0_1_9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kristaps.bsd.lv/lowdown/
COMMENT=	Simple Markdown translator
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/lowdown-${GITHUB_TAG}
HAS_CONFIGURE=	yes

SUBST_CLASSES+=		install
SUBST_SED.install+=	-e 's,/usr/local,${PREFIX},'
SUBST_FILES.install+=	configure
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Fixing installation path.

.include "../../mk/bsd.pkg.mk"
