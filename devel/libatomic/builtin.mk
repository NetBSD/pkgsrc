# $NetBSD: builtin.mk,v 1.2 2023/05/07 10:08:48 wiz Exp $

BUILTIN_PKG:=		libatomic

BUILTIN_FIND_LIBS:=	atomic

.include "../../mk/buildlink3/bsd.builtin.mk"

# Use builtin libatomic if the compiler isn't GCC
# This package is broken with non-GCC compilers.
.if ${BUILTIN_LIB_FOUND.atomic:U:tl} == yes && \
    empty(PKGSRC_COMPILER:Mgcc*)
BUILTIN_LIBNAME.libatomic=	atomic
USE_BUILTIN.libatomic=		yes
.endif
