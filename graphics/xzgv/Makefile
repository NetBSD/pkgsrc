# $NetBSD: Makefile,v 1.11 2001/10/24 22:11:03 jlam Exp $

DISTNAME=	xzgv-0.7
CATEGORIES=	graphics
MASTER_SITES=	http://xzgv.browser.org/ \
		ftp://ftp.ibiblio.org/pub/Linux/apps/graphics/viewers/X/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xzgv.browser.org/
COMMENT=	Image viewer

INFO_FILES=	xzgv

USE_BUILDLINK_ONLY=	yes
USE_X11BASE=		yes
USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC}/doc && makeinfo xzgv.texi)
	@for f in xzgv xzgv-1 xzgv-2 xzgv-3 ; do \
	${INSTALL_DATA} ${WRKSRC}/doc/$$f ${PREFIX}/info ; done

.include "../../graphics/imlib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
