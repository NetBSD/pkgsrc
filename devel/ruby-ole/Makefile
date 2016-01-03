# $NetBSD: Makefile,v 1.11 2016/01/03 06:57:05 taca Exp $
#

DISTNAME=	ruby-ole-1.2.12
PKGNAME=	${DISTNAME:S/ruby-/${RUBY_PKGPREFIX}-/}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aquasync/ruby-ole
COMMENT=	Ruby library for read/write access to OLE compound documents
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
