# $NetBSD: Makefile,v 1.12 1998/09/08 22:15:21 tron Exp $
#

DISTNAME=		qpopper2.53
PKGNAME=		qpopper-2.53
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.qualcomm.com/eudora/servers/unix/popper/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		mellon@fugue.com
HOMEPAGE=		http://eudora.qualcomm.com/freeware/qpop.html

CONFLICTS=		qpopper2.41beta1 qpopper-2.5 qpopper-2.52

MIRROR_DISTFILE=	no

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec \
			--sysconfdir=${PREFIX}/etc --enable-apop \
			--with-apop=/etc/apop.auth --with-apopuid=root

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
