# $NetBSD: Makefile,v 1.4 2012/07/13 13:15:40 obache Exp $
#

DISTNAME=	ruby-ole-1.2.11.4
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
