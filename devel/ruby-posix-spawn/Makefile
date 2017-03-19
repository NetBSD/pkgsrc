# $NetBSD: Makefile,v 1.12 2017/03/19 17:05:56 taca Exp $

DISTNAME=	posix-spawn-0.3.13
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/posix-spawn/
COMMENT=	Ruby wrapper for the posix_spawn() system call
LICENSE=	mit

# These platforms don't have posix_spawn().
# (doubtless there are more than just older netbsd...)
NOT_FOR_PLATFORM= NetBSD-[0-5]*-*

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
