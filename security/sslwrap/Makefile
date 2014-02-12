# $NetBSD: Makefile,v 1.29 2014/02/12 23:18:37 tron Exp $

DISTNAME=	${PKGNAME_NOREV:S/-//}
PKGNAME=	sslwrap-206
PKGREVISION=	7
CATEGORIES=	security net
MASTER_SITES=	http://www.rickk.com/sslwrap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rickk.com/sslwrap/
COMMENT=	Simple SSL wrapper

OPSYSVARS+=	LDADD
LDADD.SunOS=	-lnsl -lsocket
MAKE_ENV+=	LDADD=${LDADD:Q}
USE_BSD_MAKEFILE=	yes

.include "../../security/openssl/buildlink3.mk"

.if !exists(${BUILDLINK_PREFIX.openssl}/include/openssl/e_os.h)
CFLAGS+=	-DFLAT_INC
.endif

SUBST_CLASSES+=		sslwrap
SUBST_MESSAGE.sslwrap=	Adjusting the path for include files
SUBST_STAGE.sslwrap=	do-configure
SUBST_FILES.sslwrap=	apps.h s_cb.c s_server.c s_socket.c
SUBST_SED.sslwrap=	-e 's|OPENSSL"|"openssl/|'

INSTALLATION_DIRS=	sbin

.include "../../mk/bsd.pkg.mk"
