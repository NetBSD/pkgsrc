# $NetBSD: Makefile,v 1.7 2023/01/30 13:38:47 taca Exp $

DISTNAME=	dbi-0.4.5
PKGREVISION=	3
CATEGORIES=	databases

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/ruby-dbi/
COMMENT=	Database independent interface for Ruby
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-deprecated>=2.0.1<3.0:../../devel/ruby-deprecated

USE_LANGUAGES=	# empty

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
