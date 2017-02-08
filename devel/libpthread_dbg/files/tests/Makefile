# $NetBSD: Makefile,v 1.1 2017/02/08 01:37:38 kamil Exp $

NOMAN=		# defined

.include <bsd.own.mk>

TESTSDIR=	${TESTSBASE}/lib/libpthread_dbg
LDADD+=		-lpthread
LDADD+=		-lpthread_dbg

TESTS_C+=	t_dummy
TESTS_C+=	t_threads

.include <bsd.test.mk>
