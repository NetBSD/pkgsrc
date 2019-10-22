# $NetBSD: Makefile,v 1.9 2019/10/22 07:33:37 taca Exp $

DISTNAME=	archive-tar-minitar-0.8
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/halostatue/minitar
COMMENT=	Pure Ruby library for handling POSIX tar archives
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-minitar>=0.8<1:../../archivers/ruby-minitar
DEPENDS+=	${RUBY_PKGPREFIX}-minitar-cli>=0.8<1:../../archivers/ruby-minitar-cli

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
