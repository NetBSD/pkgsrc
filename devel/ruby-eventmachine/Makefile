# $NetBSD: Makefile,v 1.8 2012/09/16 06:18:08 taca Exp $

DISTNAME=	eventmachine-1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyeventmachine.com/
COMMENT=	Ruby event-driven I/O using the Reactor pattern
LICENSE=	ruby-license

USE_LANGUAGES=	c c++

.include "../../lang/ruby/gem.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
