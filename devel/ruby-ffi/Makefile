# $NetBSD: Makefile,v 1.23 2020/02/05 14:44:01 taca Exp $

DISTNAME=	ffi-1.12.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ffi/ffi/wiki
COMMENT=	Loading dynamic libraries, binding functions within them
LICENSE=	modified-bsd

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
