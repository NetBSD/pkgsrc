# $NetBSD: Makefile,v 1.6 2015/12/27 12:07:40 taca Exp $

DISTNAME=	debugger-ruby_core_source-1.3.8
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/cldwalker/debugger-ruby_core_source
COMMENT=	Provide Ruby core source files
LICENSE=	mit

RUBY_VERSION_SUPPORTED=	200

post-install:
	cd ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/lib/debugger/ruby_core_source && \
		${LN} -s ruby-2.0.0-p481 \
			ruby-${RUBY200_VERSION}-${RUBY200_PATCHLEVEL}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
