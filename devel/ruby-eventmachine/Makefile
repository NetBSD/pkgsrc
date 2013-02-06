# $NetBSD: Makefile,v 1.9 2013/02/06 23:22:10 jperkin Exp $

DISTNAME=	eventmachine-1.0.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyeventmachine.com/
COMMENT=	Ruby event-driven I/O using the Reactor pattern
LICENSE=	ruby-license

USE_LANGUAGES=	c c++

.include "../../lang/ruby/gem.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
