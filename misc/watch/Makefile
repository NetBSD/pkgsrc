# $NetBSD: Makefile,v 1.17 2015/08/18 07:31:14 wiz Exp $

DISTNAME=	procps-3.2.6
PKGNAME=	watch-3.2.6
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://procps.sourceforge.net/

MAINTAINER=	simonb@NetBSD.org
COMMENT=	Watch a program with update intervals
LICENSE=	gnu-gpl-v2

USE_BSD_MAKEFILE=	yes
USE_TOOLS=		nroff

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_ENV+=	LIBS=${LIBS:Q}

LIBS.SunOS+=	-lrt
USE_FEATURES+=	asprintf getopt_long

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
