# $NetBSD: Makefile,v 1.20 2019/01/20 13:48:30 taca Exp $

DISTNAME=	ffi-1.10.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ffi/ffi/wiki
COMMENT=	Loading dynamic libraries, binding functions within them
LICENSE=	modified-bsd

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
