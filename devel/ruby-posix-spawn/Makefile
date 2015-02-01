# $NetBSD: Makefile,v 1.9 2015/02/01 16:17:50 taca Exp $

DISTNAME=	posix-spawn-0.3.9
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtomayko/posix-spawn/
COMMENT=	Ruby wrapper for the posix_spawn() system call

LICENSE=	mit

# These platforms don't have posix_spawn().
# (doubtless there are more than just older netbsd...)
NOT_FOR_PLATFORM= NetBSD-[0-5]*-*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
