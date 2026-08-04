# $NetBSD: Makefile,v 1.21 2026/08/04 20:29:15 wiz Exp $

DISTNAME=	ccze-0.2.1
PKGREVISION=	5
CATEGORIES=	sysutils
#MASTER_SITES=	ftp://bonehunter.rulez.org/pub/ccze/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://bonehunter.rulez.org/software/ccze/
COMMENT=	Log coloriser, fast and light on resources

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILDLINK_TRANSFORM+=	rm:-Wmulticharacter

LDFLAGS.SunOS+=	-lsocket -lnsl

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
