# $NetBSD: Makefile,v 1.29 2026/02/06 08:31:41 wiz Exp $

DISTNAME=	eventmachine-1.2.7
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://rubyeventmachine.com/
COMMENT=	Ruby event-driven I/O using the Reactor pattern
LICENSE=	ruby-license

USE_LANGUAGES=	c c++11

.include "../../lang/ruby/gem.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
