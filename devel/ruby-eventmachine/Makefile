# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:16:56 jlam Exp $

DISTNAME=	eventmachine-0.10.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyeventmachine.com/
COMMENT=	Ruby event-driven I/O using the Reactor pattern

USE_LANGUAGES=	c c++
GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
