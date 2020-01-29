# $NetBSD: Makefile,v 1.9 2020/01/29 16:04:04 minskim Exp $

DISTNAME=	sgb-2007-03.28
PKGNAME=	sgb-20070328
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.stanford.edu/pub/sgb/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www-cs-faculty.stanford.edu/~knuth/sgb.html
COMMENT=	The Stanford GraphBase

DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	web2c-[0-9]*:../../print/web2c

MAKE_JOBS_SAFE=	no
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}

BUILD_TARGET=	lib doc
TEST_TARGET=	tests

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile
SUBST_VARS.paths=	LOCALBASE
SUBST_SED.paths+=	-e 's,@PREFIX@,$${DESTDIR}${PREFIX},g'

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/sgb
.for f in abstract.dvi README ERRATA
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/sgb
.endfor

.include "../../mk/bsd.pkg.mk"
