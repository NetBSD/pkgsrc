# $NetBSD: Makefile,v 1.3 2012/04/08 19:08:48 wiz Exp $
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

.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
