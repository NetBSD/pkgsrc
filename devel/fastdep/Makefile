# $NetBSD: Makefile,v 1.19 2026/08/04 20:28:50 wiz Exp $

DISTNAME=	fastdep-0.16
PKGREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	http://www.irule.be/bvh/c++/fastdep/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.irule.be/bvh/c++/fastdep/
COMMENT=	Dependency generator for C/C++ files

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

FORCE_CXX_STD=	gnu++98

INSTALLATION_DIRS=	bin

post-extract:
	${RM} -f ${WRKSRC}/*.orig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastdep ${DESTDIR}${PREFIX}/bin/fastdep

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
