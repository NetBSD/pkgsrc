# $NetBSD: Makefile,v 1.3 2015/04/19 13:30:35 tnn Exp $
#
PROGS=	as-wrapper cc-wrapper c++-wrapper cpp-wrapper f77-wrapper \
	imake-wrapper ld-wrapper libtool-wrapper shlibtool-wrapper

BINDIR=		${PREFIX}/libexec/cwrappers

LIB_SRCS=	alloc.c cleanup-cc.c common.c reorder-cc.c

.ifdef NEED_MI_VECTOR_HASH
LIB_SRCS+=	mi_vector_hash.c
CPPFLAGS+=	-DNEED_MI_VECTOR_HASH
.endif

LDADD+=		-lnbcompat

CC_SRCS=	${LIB_SRCS} generic-transform-cc.c normalise-cc.c

SRCS.as-wrapper=	${CC_SRCS} as-wrapper.c
SRCS.cc-wrapper=	${CC_SRCS} cc-wrapper.c transform-cc.c
SRCS.c++-wrapper=	${CC_SRCS} c++-wrapper.c transform-cc.c
SRCS.cpp-wrapper=	${CC_SRCS} cpp-wrapper.c
SRCS.f77-wrapper=	${CC_SRCS} f77-wrapper.c
SRCS.imake-wrapper=	${CC_SRCS} imake-wrapper.c
SRCS.ld-wrapper=	${LIB_SRCS} generic-transform-ld.c \
			normalise-ld.c ld-wrapper.c
SRCS.libtool-wrapper=	${LIB_SRCS} generic-transform-libtool.c \
			normalise-cc.c libtool-wrapper.c fixup-libtool.c
SRCS.shlibtool-wrapper=	${LIB_SRCS} generic-transform-libtool.c \
			normalise-cc.c shlibtool-wrapper.c fixup-libtool.c

WARNS=	4
NOMAN=

CLEANFILES+=	.work-new.log \
		transform-gcc-rules-fixed.map \
		transform-gcc-rules-fixed1.c \
		transform-gcc-rules-fixed2.c

transform-cc.c: transform-gcc.c

transform-gcc.c: transform-gcc-rules rules2src.awk
	awk -v output=transform-gcc.c -f rules2src.awk transform-gcc-rules

.include <bsd.prog.mk>
