# $NetBSD: Makefile,v 1.4 2018/09/23 17:58:47 taca Exp $

DISTNAME=	rex-socket-0.1.15
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/rex-socket
COMMENT=	Rex socket abstraction library
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-rex-core-[0-9]*:../../security/ruby-rex-core

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
