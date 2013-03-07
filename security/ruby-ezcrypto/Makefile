# $NetBSD: Makefile,v 1.3 2013/03/07 17:08:16 taca Exp $

DISTNAME=	ezcrypto-0.7.2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ezcrypto.rubyforge.org/
COMMENT=	Ruby object-oriented wrapper for OpenSSL libraries
LICENSE=	mit

OVERRIDE_GEMSPEC=	:files test/store= :test_files test/store=

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
