# $NetBSD: Makefile,v 1.1 2017/10/13 17:07:32 minskim Exp $

DISTNAME=	rex-mime-0.1.5
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-mime
COMMENT=	Rex Library for creating and parsing MIME messages
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-rex-text-[0-9]*:../../security/ruby-rex-text

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
