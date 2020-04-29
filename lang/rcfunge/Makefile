# $NetBSD: Makefile,v 1.9 2020/04/29 20:30:27 maya Exp $
#

DISTNAME=	rcfunge2
PKGNAME=	rcfunge-2.02
PKGREVISION=	2
DIST_SUBDIR=	rcfunge-2.02
CATEGORIES=	lang
MASTER_SITES=	http://www.rcfunge98.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.rcfunge98.com/
COMMENT=	Funge interpreter
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=			${WRKDIR}/rcfunge
BUILD_TARGET=		funge
INSTALLATION_DIRS=	bin

CFLAGS.SunOS+=	-Du_int32_t=uint32_t
LDFLAGS.SunOS+=	-lsocket -lnsl

FAKE_NCURSES=		yes # tries to link to ncurses directly

pre-build:
	${MKDIR} ${WRKSRC}/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/funge ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
