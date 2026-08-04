# $NetBSD: Makefile,v 1.18 2026/08/04 20:28:54 wiz Exp $
#

DISTNAME=	pcf2bdf-1.07
CATEGORIES=	fonts graphics x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ganaware/}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	https://github.com/ganaware/pcf2bdf
COMMENT=	Convert X font from PCF to BDF
LICENSE=	mit

USE_TOOLS+=	gmake
USE_LANGUAGES=	c++
MAKE_FILE=	Makefile.gcc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o pcf2bdf pcf2bdf.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcf2bdf ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pcf2bdf.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pcf2bdf.1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
