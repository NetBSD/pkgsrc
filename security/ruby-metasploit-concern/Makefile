# $NetBSD: Makefile,v 1.1 2017/09/14 17:46:23 minskim Exp $

DISTNAME=	metasploit-concern-2.0.5
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-concern
COMMENT=	Automatically include concern modules
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-activemodel42>=4.2.6:../../devel/ruby-activemodel42
DEPENDS+=	${RUBY_PKGPREFIX}-activesupport42>=4.2.6:../../devel/ruby-activesupport42
DEPENDS+=	${RUBY_PKGPREFIX}-railties42>=4.2.6:../../devel/ruby-railties42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
