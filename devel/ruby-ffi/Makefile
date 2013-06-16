# $NetBSD: Makefile,v 1.11 2013/06/16 15:00:20 taca Exp $

DISTNAME=	ffi-1.9.0
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
