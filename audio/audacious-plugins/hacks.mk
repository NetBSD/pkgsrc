# $NetBSD: hacks.mk,v 1.1 2019/07/06 13:17:01 nia Exp $

.if !defined(AUDACIOUS_PLUGINS_HACKS_MK)
AUDACIOUS_PLUGINS_HACKS_MK:=

.include "../../mk/compiler.mk"

.if empty(PKGSRC_COMPILER:Mclang)
# This should avoid an error like: libstdc++.so.6: Undefined PLT symbol "_Unwind_GetIP" on NetBSD i386 and maybe amd64, with gcc4 at least.
# This seems to happen when libstdc++ gets linked in with the plug-ins and the code is not compiled with g++.
# For a similar problem see http://archive.netbsd.se/?ml=netbsd-java&a=2007-08&m=4912662 :
# Systems with Clang are supposed to be new enough to have a correctly linked
# libstdc++.
LDFLAGS.NetBSD+=	-lgcc_s
.endif

# From audio/bmp/Makefile:
# XXX Workaround a crash during shutdown that happens when dlclose(3)ing
# any open plugin.  libstdc++ gets dynamically linked in when the id3lib
# library is loaded, and is the one causing problems.  See PR pkg/26846
# for more information.
LDFLAGS.NetBSD+=	-lstdc++ -lm
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS.SunOS=		-D__EXTENSIONS__ -D__uint32_t=uint32_t -D__uint64_t=uint64_t
.endif
