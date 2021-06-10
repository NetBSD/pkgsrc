# $NetBSD: Makefile,v 1.1 2021/06/10 14:31:04 taca Exp $

DISTNAME=	red-datasets-0.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/red-data-tools/red-datasets
COMMENT=	Provide common datasets such as iris dataset
LICENSE=	mit

# All ruby*-base packages contain required csv and rexml gem.
#DEPENDS+=	${RUBY_PKGPREFIX}-csv>=3.0.5:../../textproc/ruby-csv
#DEPENDS+=	${RUBY_PKGPREFIX}-rexml>=0:../../textproc/ruby-rexml
DEPENDS+=	${RUBY_PKGPREFIX}-zip>=0:../../archivers/ruby-zip

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
