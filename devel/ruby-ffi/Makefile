# $NetBSD: Makefile,v 1.1.1.1 2010/09/23 07:18:01 taca Exp $

DISTNAME=	ffi-0.6.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.github.com/ffi/ffi
COMMENT=	Loading dynamic libraries, binding functions within them
LICENSE=	mit

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
