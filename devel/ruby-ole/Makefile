# $NetBSD: Makefile,v 1.5 2012/10/31 11:19:42 asau Exp $
#

DISTNAME=	ruby-ole-1.2.11.4
PKGNAME=	${DISTNAME:S/ruby-/${RUBY_PKGPREFIX}-/}
CATEGORIES=	devel

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ruby-ole/
COMMENT=	Ruby library for read/write access to OLE compound documents
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
