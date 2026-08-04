# $NetBSD: Makefile,v 1.25 2026/08/04 20:29:08 wiz Exp $

DISTNAME=	src-mdp-1.9a5
PKGNAME=	${DISTNAME:S/src-//}
PKGREVISION=	1
CATEGORIES=	mbone
MASTER_SITES=	#
DISTFILES=	src-mdp-1.9a5.tgz src-protolib-1.0a3d.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://cs.itd.nrl.navy.mil/work/mdp/
COMMENT=	Multicast file transfer

WRKSRC=		${WRKDIR}/mdp
BUILD_DIRS=	unix
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
BUILD_TARGET=	mdp

INSTALLATION_DIRS=	bin

post-extract:
	rm ${WRKSRC}/protolib
	mv ${WRKDIR}/protolib-1.0 ${WRKSRC}/protolib

do-configure:
	cd ${WRKSRC}/unix && rm -f Makefile && ln -s Makefile.netbsd Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/mdp ${DESTDIR}${PREFIX}/bin

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
