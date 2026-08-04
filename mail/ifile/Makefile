# $NetBSD: Makefile,v 1.17 2026/08/04 20:29:05 wiz Exp $
#

DISTNAME=	ifile-1.3.8
CATEGORIES=	mail
MASTER_SITES=	http://qwone.com/~jason/ifile/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://qwone.com/~jason/ifile/
COMMENT=	Intelligent mail filtering system

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifile ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifile.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
