# $NetBSD: Makefile,v 1.1 2026/05/18 12:20:35 nia Exp $

DISTNAME=	cbonsai-1.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITLAB:=jallbrit/}
GITLAB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/jallbrit/cbonsai
COMMENT=	Grow bonsai trees in your terminal
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGBASE}-${GITLAB_TAG}

USE_TOOLS+=	gmake pkg-config

TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

BUILD_TARGET=	cbonsai cbonsai.6

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
