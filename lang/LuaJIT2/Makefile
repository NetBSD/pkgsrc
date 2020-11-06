# $NetBSD: Makefile,v 1.16 2020/11/06 12:15:53 nia Exp $
#

DISTNAME=	LuaJIT-2.0.5
PKGNAME=	${DISTNAME:S/LuaJIT/LuaJIT2/}
PKGREVISION=	2
CATEGORIES=	lang lua
MASTER_SITES=	http://luajit.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

USE_TOOLS+=	gmake

# LuaJIT 2.1.0 will support mips64 and aarch64.
ONLY_FOR_PLATFORM+=	*-*-*arm*
ONLY_FOR_PLATFORM+=	*-*-i386
ONLY_FOR_PLATFORM+=	*-*-mipseb
ONLY_FOR_PLATFORM+=	*-*-mipsel
ONLY_FOR_PLATFORM+=	*-*-powerpc
ONLY_FOR_PLATFORM+=	*-*-x86_64

# Address pkg/47587 lua not linked to pthread causes issues with modules
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
