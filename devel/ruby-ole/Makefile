# $NetBSD: Makefile,v 1.14 2024/04/07 14:41:25 taca Exp $
#

DISTNAME=	ruby-ole-1.2.13.1
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
