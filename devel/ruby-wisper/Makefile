# $NetBSD: Makefile,v 1.2 2023/02/23 14:49:24 taca Exp $

DISTNAME=	wisper-2.0.1
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/krisleech/wisper
COMMENT=	Providing objects with Publish-Subscribe capabilities
LICENSE=	mit

#DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=2.0:../../misc/ruby-bundler
DEPENDS+=	${RUBY_PKGPREFIX}-pry>=0.12.1:../../misc/ruby-pry

USE_LANGUAGES=	# empty
USE_TOOLS=	bash:run
REPLACE_BASH=	bin/setup

RUBYGEM_OPTIONS+=	--format-executable
WISPER_COMMANDS=	console setup

post-install:
.for f in ${WISPER_COMMANDS}
	mv ${DESTDIR}${PREFIX}/bin/${f}${RUBY_SUFFIX} \
		${DESTDIR}${PREFIX}/bin/wisper-${f}${RUBY_SUFFIX}
.endfor

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
