# $NetBSD: Makefile,v 1.6 2012/07/31 13:54:48 taca Exp $

DISTNAME=	ffi-1.1.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.github.com/ffi/ffi
COMMENT=	Loading dynamic libraries, binding functions within them
LICENSE=	mit

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
