# $NetBSD: Makefile,v 1.18 2017/01/04 21:41:39 roy Exp $

DISTNAME=	procps-3.2.6
PKGNAME=	watch-3.2.6
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Watch a program with update intervals
LICENSE=	gnu-gpl-v2

USE_BSD_MAKEFILE=	yes
USE_TOOLS=		nroff
FAKE_NCURSES=		yes

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_ENV+=	LIBS=${LIBS:Q}

LIBS.SunOS+=	-lrt
USE_FEATURES+=	asprintf getopt_long

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
