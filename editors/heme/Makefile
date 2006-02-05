# $NetBSD: Makefile,v 1.3 2006/02/05 23:08:56 joerg Exp $
#

DISTNAME=		heme-0.4
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heme/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://sourceforge.net/projects/heme/
COMMENT=		Fast and portable console hex editor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		heme
USE_NCURSES=		# mvwchgat
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heme ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/heme.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
