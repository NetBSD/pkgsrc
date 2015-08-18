# $NetBSD: Makefile,v 1.6 2015/08/18 07:31:10 wiz Exp $
#

DISTNAME=	rcfunge2
PKGNAME=	rcfunge-2.02
PKGREVISION=	2
DIST_SUBDIR=	rcfunge-2.02
CATEGORIES=	lang
MASTER_SITES=	http://www.rcfunge98.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rcfunge98.com/
COMMENT=	Funge interpreter
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=	${WRKDIR}/rcfunge
BUILD_TARGET=	funge
INSTALLATION_DIRS=	bin

CFLAGS.SunOS+=	-Du_int32_t=uint32_t
LDFLAGS.SunOS+=	-lsocket -lnsl

# keypad(3) return value was fixed after -5 branch (might be pulled up)
INCOMPAT_CURSES+=	NetBSD-[0-4]*-* NetBSD-5.[0-8]*-*
FAKE_NCURSES=		yes # tries to link to ncurses directly

pre-build:
	${MKDIR} ${WRKSRC}/bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/funge ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
