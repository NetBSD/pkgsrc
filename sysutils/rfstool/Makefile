# $NetBSD: Makefile,v 1.14 2023/08/02 19:21:57 nia Exp $
#

DISTNAME=	rfstool-0.14-source
PKGNAME=	rfstool-0.14
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://p-nand-q.com/download/rfstool/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://p-nand-q.com/download/rfstool/overview.html
COMMENT=	Tools to access ReiserFS partitions

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/RFSTOOL
MAKE_FILE=	makefile.gcc3x
USE_LANGUAGES=	c c++

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rfstool ${DESTDIR}${PREFIX}/sbin/rfstool

.include "../../mk/bsd.pkg.mk"
