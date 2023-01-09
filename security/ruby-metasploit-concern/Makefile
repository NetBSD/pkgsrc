# $NetBSD: Makefile,v 1.9 2023/01/09 05:45:49 taca Exp $

DISTNAME=	metasploit-concern-5.0.0
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-concern
COMMENT=	Automatically include concern modules
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	70

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
