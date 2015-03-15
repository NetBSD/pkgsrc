# $NetBSD: Makefile,v 1.14 2015/03/15 16:04:57 taca Exp $

DISTNAME=	ffi-1.9.8
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.github.com/ffi/ffi
COMMENT=	Loading dynamic libraries, binding functions within them
LICENSE=	modified-bsd

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
