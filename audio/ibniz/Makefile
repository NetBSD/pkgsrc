# $NetBSD: Makefile,v 1.5 2026/08/04 20:28:44 wiz Exp $
#

DISTNAME=	ibniz-1.18
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://pelulamu.net/ibniz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pelulamu.net/ibniz/
COMMENT=	Virtual machine designed for extremely compact audiovisual programs
LICENSE=	zlib

INSTALLATION_DIRS=	bin share/doc/ibniz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ibniz ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ibniz.txt ${DESTDIR}${PREFIX}/share/doc/ibniz

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
