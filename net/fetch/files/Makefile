# $FreeBSD$

.include <bsd.own.mk>

PROG=		fetch
LDADD=		-lfetch

FETCH_WITH_OPENSSL?=	no

.if ${FETCH_WITH_OPENSSL} != "no"
LDADD+=		-lssl -lcrypto
.endif

.include <bsd.prog.mk>
