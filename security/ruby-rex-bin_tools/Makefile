# $NetBSD: Makefile,v 1.1 2017/10/13 18:11:49 minskim Exp $

DISTNAME=	rex-bin_tools-0.1.4
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-bin_tools
COMMENT=	Ruby Exploitation Library for binary manipulation
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-metasm-[0-9]*:../../devel/ruby-metasm
DEPENDS+=	${RUBY_PKGPREFIX}-rex-arch-[0-9]*:../../security/ruby-rex-arch
DEPENDS+=	${RUBY_PKGPREFIX}-rex-core-[0-9]*:../../security/ruby-rex-core
DEPENDS+=	${RUBY_PKGPREFIX}-rex-struct2-[0-9]*:../../security/ruby-rex-struct2
DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
