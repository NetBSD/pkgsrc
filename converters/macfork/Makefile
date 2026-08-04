# $NetBSD: Makefile,v 1.21 2026/08/04 20:28:47 wiz Exp $

DISTNAME=	macfork-1.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.cs.cmu.edu/~ajw/public/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cs.cmu.edu/afs/cs/user/ajw/www/software/
COMMENT=	Tool for extracting data from Macintosh resource forks

WRKSRC=		${WRKDIR}/macfork
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

DOCDIR=		${PREFIX}/share/doc/macfork

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/macfork ${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DESTDIR}${DOCDIR}

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
