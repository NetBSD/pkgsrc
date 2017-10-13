# $NetBSD: Makefile,v 1.1 2017/10/13 18:51:42 minskim Exp $

DISTNAME=	rex-encoder-0.1.4
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-encoder
COMMENT=	Polymorphic encoders that Metasploit uses for payload encoding
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-metasm-[0-9]*:../../devel/ruby-metasm
DEPENDS+=	${RUBY_PKGPREFIX}-rex-arch-[0-9]*:../../security/ruby-rex-arch
DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
