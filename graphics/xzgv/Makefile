# $NetBSD: Makefile,v 1.28 2005/06/16 06:57:59 jlam Exp $

DISTNAME=	xzgv-0.8
PKGNAME=	xzgv-0.8.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/apps/graphics/viewers/X/

PATCHFILES=	xzgv-0.8-integer-overflow-fix.diff
PATCH_SITES=	http://rus.members.beeb.net/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rus.members.beeb.net/xzgv.html
COMMENT=	Image viewer

USE_MAKEINFO=	YES
INFO_FILES=	xzgv

USE_X11BASE=		yes
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin info man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC}/doc && ${MAKEINFO} xzgv.texi)
	@for f in xzgv xzgv-1 xzgv-2 xzgv-3 ; do \
	${INSTALL_DATA} ${WRKSRC}/doc/$$f ${PREFIX}/info ; done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
