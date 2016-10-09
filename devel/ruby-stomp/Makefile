# $NetBSD: Makefile,v 1.9 2016/10/09 15:10:43 taca Exp $

DISTNAME=	stomp-1.4.3
CATEGORIES=	devel

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://rubygems.org/gems/stomp/
COMMENT=	Ruby library for the Stomp protocol
LICENSE=	apache-2.0

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	rake: stomp: rspec:

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
