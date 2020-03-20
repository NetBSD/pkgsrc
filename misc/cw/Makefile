# $NetBSD: Makefile,v 1.4 2020/03/20 11:58:01 nia Exp $

DISTNAME=	cw-1.0.16
CATEGORIES=	misc
MASTER_SITES=	http://cwrapper.sourceforge.net/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://cwrapper.sourceforge.net/
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
