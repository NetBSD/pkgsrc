# $NetBSD: Makefile,v 1.5 2012/02/24 20:04:14 joerg Exp $
#

VERSION=	1.2.1
DISTNAME=	argparse-${VERSION}
PKGNAME=	${PYPKGPREFIX}-argparse-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://argparse.googlecode.com/files/
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://code.google.com/p/argparse/
COMMENT=	Easy, declarative interface for creating command line tools
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir
#PYTHON_VERSIONS_INCLUDE_3X=	yes

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
