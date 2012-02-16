# $NetBSD: Makefile,v 1.25 2012/02/16 19:42:04 hans Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/-//}
PKGNAME=	sslwrap-206
PKGREVISION=	5
CATEGORIES=	security net
MASTER_SITES=	http://www.rickk.com/sslwrap/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.rickk.com/sslwrap/
COMMENT=	Simple SSL wrapper

PKG_DESTDIR_SUPPORT=	user-destdir

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
