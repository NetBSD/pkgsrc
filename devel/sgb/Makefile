# $NetBSD: Makefile,v 1.3 2009/03/04 16:54:26 minskim Exp $

DISTNAME=	sgb-2007-03.28
PKGNAME=	sgb-20070328
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.stanford.edu/pub/sgb/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www-cs-faculty.stanford.edu/~uno/sgb.html
COMMENT=	The Stanford GraphBase

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}

BUILD_TARGET=	lib doc
TEST_TARGET=	tests

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's,@PREFIX@,$${DESTDIR}${PREFIX},g'

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/sgb
.for f in abstract.dvi README ERRATA
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/sgb
.endfor

.include "../../mk/bsd.pkg.mk"
