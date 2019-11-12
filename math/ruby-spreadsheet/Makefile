# $NetBSD: Makefile,v 1.52 2019/11/12 20:28:14 wiz Exp $

DISTNAME=	spreadsheet-1.2.5
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zdavatz/spreadsheet
COMMENT=	Ruby Spreadsheet Library to read and write Spreadsheet Documents
LICENSE=	gnu-gpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-ole>=1.0:../../devel/ruby-ole

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
