# $NetBSD: Makefile,v 1.8 2016/06/21 16:40:10 fhajny Exp $
#

DISTNAME=	LuaJIT-2.0.4
PKGNAME=	${DISTNAME:S/LuaJIT/LuaJIT2/}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://luajit.org/download/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	http://luajit.org/
COMMENT=	Just-In-Time Compiler for the Lua programming language
LICENSE=	mit

USE_TOOLS+=	gmake

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
