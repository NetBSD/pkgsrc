# $NetBSD: Makefile,v 1.23 2018/01/26 13:17:27 jperkin Exp $

DISTNAME=	eventmachine-1.2.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyeventmachine.com/
COMMENT=	Ruby event-driven I/O using the Reactor pattern
LICENSE=	ruby-license

USE_LANGUAGES=	c c++03

.include "../../lang/ruby/gem.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
