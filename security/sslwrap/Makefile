# $NetBSD: Makefile,v 1.20 2006/10/04 21:58:14 wiz Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/-//}
PKGNAME=	sslwrap-206
PKGREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	http://www.rickk.com/sslwrap/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.rickk.com/sslwrap/
COMMENT=	Simple SSL wrapper


OPSYSVARS+=	LDADD
LDADD.SunOS=	-lnsl -lsocket
MAKE_ENV+=	LDADD=${LDADD:Q}
MAKE_ENV+=	BINOWN=${BINOWN:Q}
MAKE_ENV+=	BINGRP=${BINGRP:Q}

.include "../../security/openssl/buildlink3.mk"

.if !exists(${BUILDLINK_PREFIX.openssl}/include/openssl/e_os.h)
CFLAGS+=	-DFLAT_INC
.endif

SUBST_CLASSES+=		sslwrap
SUBST_MESSAGE.sslwrap=	Adjusting the path for include files
SUBST_STAGE.sslwrap=	do-configure
SUBST_FILES.sslwrap=	apps.h s_cb.c s_server.c s_socket.c
SUBST_SED.sslwrap=	-e 's|OPENSSL"|"openssl/|'

.include "../../mk/bsd.pkg.mk"
