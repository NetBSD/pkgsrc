# $NetBSD: Makefile,v 1.16 2004/10/03 00:18:13 tv Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/-//}
PKGNAME=	sslwrap-206
PKGREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	http://www.quiltaholic.com/rickk/sslwrap/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.quiltaholic.com/rickk/sslwrap/
COMMENT=	Simple SSL wrapper

USE_BUILDLINK3=	YES

OPSYSVARS+=	LDADD
LDADD.SunOS=	-lnsl -lsocket
MAKE_ENV+=	LDADD="${LDADD}"

.include "../../security/openssl/buildlink3.mk"

.if !exists(${BUILDLINK_PREFIX.openssl}/include/openssl/e_os.h)
CFLAGS+=	-DFLAT_INC
.endif

do-configure:
.for f in apps.h s_cb.c s_server.c s_socket.c
	sed -e 's|OPENSSL"|"openssl/|' ${WRKSRC}/$f > ${WRKSRC}/$f.not && \
		mv ${WRKSRC}/$f.not ${WRKSRC}/$f
.endfor

.include "../../mk/bsd.pkg.mk"
