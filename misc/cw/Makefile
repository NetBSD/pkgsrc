# $NetBSD: Makefile,v 1.6 2026/08/04 20:29:08 wiz Exp $

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

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
