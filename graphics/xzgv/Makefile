# $NetBSD: Makefile,v 1.32 2006/03/19 15:33:24 wiz Exp $

DISTNAME=	xzgv-0.8
PKGNAME=	xzgv-0.8.0.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/apps/graphics/viewers/X/

PATCHFILES=	xzgv-0.8-integer-overflow-fix.diff
PATCH_SITES=	http://rus.members.beeb.net/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/xzgv.html
COMMENT=	Image viewer

USE_X11BASE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		xzgv
INSTALLATION_DIRS=	bin info man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC}/doc && ${MAKEINFO} xzgv.texi)
	${INSTALL_DATA} ${WRKSRC}/doc/xzgv ${PREFIX}/info

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
