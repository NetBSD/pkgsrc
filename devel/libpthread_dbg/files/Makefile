#	$NetBSD: Makefile,v 1.1 2017/02/08 01:02:19 kamil Exp $
#

#.include <bsd.own.mk>

LIB=	pthread_dbg

SRCS=	pthread_dbg.c 

CPPFLAGS+=	-D__LIBPTHREAD_SOURCE__

.if defined(PTHREAD_MACHINE_ARCH) && !empty(PTHREAD_MACHINE_ARCH) && \
    exists(${.CURDIR}/arch/${PTHREAD_MACHINE_ARCH})
ARCHSUBDIR=     ${PTHREAD_MACHINE_ARCH}
.elif exists(${.CURDIR}/arch/${MACHINE_ARCH})
ARCHSUBDIR=     ${MACHINE_ARCH}
.elif exists(${.CURDIR}/arch/${MACHINE_CPU})
ARCHSUBDIR=     ${MACHINE_CPU}
.else
.BEGIN:
	@echo "no ARCHSUBDIR for ${MACHINE_ARCH}/${MACHINE_CPU}; skipping..."
.endif

ARCHDIR=        ${.CURDIR}/arch/${ARCHSUBDIR}

CPPFLAGS+=      -I${ARCHDIR}

INCS=	pthread_dbg.h

MAN+=	pthread_dbg.3
MAN+=	td_open.3
MAN+=	td_map_pth2thr.3
MAN+=	td_thr_getname.3
MAN+=	td_thr_info.3
MAN+=	td_thr_iter.3

MLINKS+=	td_open.3 td_close.3

.include <bsd.lib.mk>
