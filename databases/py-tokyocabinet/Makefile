# $NetBSD: Makefile,v 1.4 2012/10/02 21:25:50 asau Exp $
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

.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
