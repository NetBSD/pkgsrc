# $NetBSD: Makefile,v 1.3 2017/09/08 06:16:15 wiz Exp $

DISTNAME=	ii-1.7
CATEGORIES=	chat
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://dl.suckless.org/tools/
COMMENT=	Minimalist FIFO and filesystem-based IRC client
LICENSE=	mit

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'
SUBST_SED.makefile+=	-e 's,^LDFLAGS,\#LDFLAGS,g'

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
