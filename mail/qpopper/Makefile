# $NetBSD: Makefile,v 1.17 1999/08/18 09:01:49 agc Exp $
#

DISTNAME=		qpopper2.53
PKGNAME=		qpopper-2.53
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://eudora.qualcomm.com/freeware/qpop.html

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec \
			--sysconfdir=${PREFIX}/etc --enable-apop \
			--with-apop=/etc/apop.auth --with-apopuid=root

BUILD_DEFS+=		QPOPPER_SERVERMODE USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(QPOPPER_SERVERMODE)
CONFIGURE_ARGS+=	--enable-servermode
.endif
.if defined(USE_INET6)
CONFIGURE_ENV+=		O_DEFS="${O_DEFS}" CFLAGS="-DINET6"
.endif

# popper makefile doesn't have an install target...
do-install:
	(cd ${WRKSRC}; \
	 ${INSTALL} -o ${BINOWN} -c -g ${BINGRP} -m ${BINMODE} popper \
					${LOCALBASE}/libexec/qpopper; \
	 ${INSTALL} -o root -c -g ${BINGRP} -m 4755 popauth \
					${LOCALBASE}/bin/qpopauth; \
	 ${INSTALL} -o ${MANOWN} -c -g ${MANGRP} -m ${MANMODE} popper.8 \
					${LOCALBASE}/man/man8/qpopper.8; \
	 ${INSTALL} -o ${MANOWN} -c -g ${MANGRP} -m ${MANMODE} popauth.8 \
					${LOCALBASE}/man/man8/qpopauth.8 )

.include "../../mk/bsd.pkg.mk"
