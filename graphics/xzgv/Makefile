# $NetBSD: Makefile,v 1.21 2004/01/03 18:49:45 reed Exp $

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

USE_BUILDLINK2=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xzgv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xzgv.1 ${PREFIX}/man/man1
	@(cd ${WRKSRC}/doc && ${MAKEINFO} xzgv.texi)
	@for f in xzgv xzgv-1 xzgv-2 xzgv-3 ; do \
	${INSTALL_DATA} ${WRKSRC}/doc/$$f ${PREFIX}/info ; done

.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
