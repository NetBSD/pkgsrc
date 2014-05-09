# $NetBSD: Makefile,v 1.6 2014/05/09 07:36:58 wiz Exp $

VERSION=	0.5
DISTNAME=	tokyocabinet-${VERSION}
PKGNAME=	${PYPKGPREFIX}-tokyocabinet-${VERSION}
CATEGORIES=	databases
MASTER_SITES=	http://python-tokyocabinet.googlecode.com/files/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://code.google.com/p/python-tokyocabinet/
COMMENT=	Python wrapper to tokyocabinet database
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.5

.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
