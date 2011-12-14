# $NetBSD: Makefile,v 1.5 2011/12/14 17:03:07 taca Exp $

DISTNAME=	ffi-1.0.11
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.github.com/ffi/ffi
COMMENT=	Loading dynamic libraries, binding functions within them
LICENSE=	mit

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
