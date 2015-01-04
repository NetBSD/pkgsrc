# $NetBSD: Makefile,v 1.8 2015/01/04 02:52:58 dholland Exp $

DISTNAME=	posix-spawn-0.3.8
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
