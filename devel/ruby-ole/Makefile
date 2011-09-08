# $NetBSD: Makefile,v 1.2 2011/09/08 10:49:41 obache Exp $
#

DISTNAME=	ruby-ole-1.2.11.2
PKGNAME=	${DISTNAME:S/ruby-/${RUBY_PKGPREFIX}-/}
CATEGORIES=	devel

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ruby-ole/
COMMENT=	Ruby library for read/write access to OLE compound documents
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
