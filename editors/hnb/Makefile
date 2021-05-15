# $NetBSD: Makefile,v 1.32 2021/05/15 12:04:18 nia Exp $

DISTNAME=	hnb-1.9.18
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=fraggerfox/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hnb.sourceforge.net/
COMMENT=	Hierarchical data organizer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hnb ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/hnb.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
