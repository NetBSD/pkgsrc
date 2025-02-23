# $NetBSD: Makefile,v 1.6 2025/02/23 14:24:08 taca Exp $

DISTNAME=	rex-encoder-0.1.8
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-encoder
COMMENT=	Polymorphic encoders that Metasploit uses for payload encoding
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-metasm-[0-9]*:../../devel/ruby-metasm
DEPENDS+=	${RUBY_PKGPREFIX}-rex-arch-[0-9]*:../../security/ruby-rex-arch
DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
