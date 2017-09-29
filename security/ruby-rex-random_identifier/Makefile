# $NetBSD: Makefile,v 1.1 2017/09/29 16:51:00 minskim Exp $

DISTNAME=	rex-random_identifier-0.1.4
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-random_identifier
COMMENT=	Ruby Exploitation library for generating random identifiers
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
