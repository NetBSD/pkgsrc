# $NetBSD: Makefile,v 1.1 2022/01/16 13:23:06 taca Exp $

DISTNAME=	gdbm-2.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/gdbm/gdbm-gem/}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/gdbm
COMMENT=	Ruby extension for GNU dbm
LICENSE=	2-clause-bsd

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
