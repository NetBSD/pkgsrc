# $NetBSD: Makefile,v 1.23 2004/04/26 04:36:24 snj Exp $

DISTNAME=	xzgv-0.7
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://xzgv.browser.org/ \
		ftp://ftp.ibiblio.org/pub/Linux/apps/graphics/viewers/X/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xzgv.browser.org/
COMMENT=	Image viewer

USE_MAKEINFO=	YES
INFO_FILES=	xzgv

USE_BUILDLINK3=		yes
USE_X11BASE=		yes
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC}/doc && ${MAKEINFO} xzgv.texi)
	@for f in xzgv xzgv-1 xzgv-2 xzgv-3 ; do \
	${INSTALL_DATA} ${WRKSRC}/doc/$$f ${PREFIX}/info ; done

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
