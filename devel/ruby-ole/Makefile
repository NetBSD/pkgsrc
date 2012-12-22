# $NetBSD: Makefile,v 1.6 2012/12/22 08:35:31 obache Exp $
#

DISTNAME=	ruby-ole-1.2.11.5
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
