# $NetBSD: Makefile,v 1.13 2017/01/03 17:47:56 roy Exp $
#

DISTNAME=		heme-0.4.2
PKGREVISION=		3
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heme/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/heme/
COMMENT=		Fast and portable console hex editor
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		heme
USE_TOOLS+=		gmake

USE_CURSES=		chgat
FAKE_NCURSES=		yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heme ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/heme.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
