# $NetBSD: Makefile,v 1.6 2010/03/17 15:44:00 joerg Exp $
#

DISTNAME=		heme-0.4
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heme/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://sourceforge.net/projects/heme/
COMMENT=		Fast and portable console hex editor

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		heme
USE_NCURSES=		chgat
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heme ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/heme.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
