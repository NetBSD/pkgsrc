# $NetBSD: Makefile,v 1.2 2012/03/05 08:26:17 dholland Exp $
#

VERSION=	0.5
DISTNAME=	tokyocabinet-${VERSION}
PKGNAME=	${PYPKGPREFIX}-tokyocabinet-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	http://python-tokyocabinet.googlecode.com/files/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://code.google.com/p/python-tokyocabinet/
COMMENT=	Python wrapper to tokyocabinet database
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24

.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
