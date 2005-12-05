# $NetBSD: Makefile,v 1.3 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=	rfstool-0.14-source
PKGNAME=	rfstool-0.14
CATEGORIES=	sysutils
MASTER_SITES=	http://p-nand-q.com/download/rfstool/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://p-nand-q.com/download/rfstool/overview.html
COMMENT=	Tools to access ReiserFS partitions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/rfstool
MAKEFILE=	makefile.gcc3x
USE_LANGUAGES+=	c++

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rfstool ${PREFIX}/sbin/rfstool

.include "../../mk/bsd.pkg.mk"
