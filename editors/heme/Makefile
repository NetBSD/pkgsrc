# $NetBSD: Makefile,v 1.12 2015/08/18 07:31:06 wiz Exp $
#

DISTNAME=		heme-0.4.2
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heme/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/heme/
COMMENT=		Fast and portable console hex editor
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		heme
USE_NCURSES=		chgat
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heme ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/heme.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
