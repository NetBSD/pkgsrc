# $NetBSD: Makefile,v 1.12 2024/06/30 16:20:07 taca Exp $

DISTNAME=	metasploit-concern-5.0.3
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-concern
COMMENT=	Automatically include concern modules
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	70 71

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
