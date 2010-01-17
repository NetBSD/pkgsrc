# $NetBSD: Makefile,v 1.5 2010/01/17 12:02:15 wiz Exp $

DISTNAME=	eventmachine-0.12.10
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyeventmachine.com/
COMMENT=	Ruby event-driven I/O using the Reactor pattern
LICENSE=	ruby-license

USE_LANGUAGES=	c c++
GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
