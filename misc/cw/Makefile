# $NetBSD: Makefile,v 1.5 2025/11/17 11:01:08 wiz Exp $

DISTNAME=	cw-1.0.16
CATEGORIES=	misc
MASTER_SITES=	http://cwrapper.sourceforge.net/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://cwrapper.sourceforge.net/
COMMENT=	Non-intrusive color wrapper for common commands
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Updating intepreter path
SUBST_FILES.path=	def/*
SUBST_SED.path=		-e 's,/cw,${PREFIX}/bin/cw,1'

.include "../../mk/bsd.pkg.mk"
