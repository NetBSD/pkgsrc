# $NetBSD: Makefile,v 1.7 2012/08/21 13:52:10 taca Exp $

DISTNAME=	ffi-1.1.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.github.com/ffi/ffi
COMMENT=	Loading dynamic libraries, binding functions within them
LICENSE=	mit

USE_RAKE=	YES
RUBY_RDOC_REQD=	3.9.4

OVERRIDE_GEMSPEC+= :files gen/log=

.include "../../lang/ruby/gem.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
