# $NetBSD: Makefile,v 1.24 2020/03/08 16:42:26 bsiegert Exp $

DISTNAME=	ffi-1.12.2
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ffi/ffi/wiki
COMMENT=	Loading dynamic libraries, binding functions within them
LICENSE=	modified-bsd

USE_RAKE=	YES

.include "../../lang/ruby/gem.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
