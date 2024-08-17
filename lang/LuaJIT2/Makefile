# $NetBSD: Makefile,v 1.17 2024/08/17 15:20:20 bsiegert Exp $

DISTNAME=	LuaJIT-2.1.1713773202	# see .relver
PKGNAME=	${DISTNAME:S/LuaJIT/LuaJIT2/}
CATEGORIES=	lang lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=LuaJIT/}
GITHUB_PROJECT=	LuaJIT
GITHUB_TAG=	5790d253972c9d78a0c2aece527eda5b134bbbf7

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM+=	*-*-aarch64*
ONLY_FOR_PLATFORM+=	*-*-*arm*	# ARMv5+, ARM9E+
ONLY_FOR_PLATFORM+=	*-*-i386	# req SSE2
ONLY_FOR_PLATFORM+=	*-*-mips*
ONLY_FOR_PLATFORM+=	*-*-powerpc
ONLY_FOR_PLATFORM+=	*-*-x86_64

# pkg/47587: lua not linked to pthread causes issues with modules
PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes

.include "../../mk/bsd.prefs.mk"

# Upstream doesn't support building shared libs on SunOS
# http://www.freelists.org/post/luajit/LuaJIT-on-solaris-64
PLIST_VARS+=		shared
.if ${OPSYS} != "SunOS"
PLIST.shared=		yes
.endif
PRINT_PLIST_AWK+=	{if ($$0 ~ /\.so/) {$$0 = "$${PLIST.shared}" $$0;}}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
