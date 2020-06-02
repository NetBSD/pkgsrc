# $NetBSD: builtin.mk,v 1.1 2020/06/02 21:26:03 maya Exp $

BUILTIN_PKG:=		libatomic

BUILTIN_FIND_LIBS:=	atomic

.include "../../mk/buildlink3/bsd.builtin.mk"

# Use builtin libatomic if the compiler isn't GCC
# This package is broken with non-GCC compilers.
.if !empty(BUILTIN_LIB_FOUND.atomic:M[yY][eE][sS]) && \
    empty(PKGSRC_COMPILER:Mgcc*)
BUILTIN_LIBNAME.libatomic=	atomic
USE_BUILTIN.libatomic=		yes
.endif
