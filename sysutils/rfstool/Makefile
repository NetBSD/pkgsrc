# $NetBSD: Makefile,v 1.6 2006/09/09 02:46:08 obache Exp $
#

DISTNAME=	rfstool-0.14-source
PKGNAME=	rfstool-0.14
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://p-nand-q.com/download/rfstool/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://p-nand-q.com/download/rfstool/overview.html
COMMENT=	Tools to access ReiserFS partitions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/rfstool
MAKE_FILE=	makefile.gcc3x
USE_LANGUAGES+=	c++

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rfstool ${PREFIX}/sbin/rfstool

.include "../../mk/bsd.pkg.mk"
