# $NetBSD: Makefile,v 1.9 1998/07/02 07:09:03 hubertf Exp $
#

DISTNAME=	qpopper2.52
PKGNAME=	qpopper-2.52
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.qualcomm.com/eudora/servers/unix/popper/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     mellon@fugue.com

CONFLICTS=	qpopper2.41beta1 qpopper-2.5

MIRROR_DISTFILE=	no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --libexecdir=${PREFIX}/libexec --sysconfdir=${PREFIX}/etc \
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
					${LOCALBASE}/man/man8/qpopauth.8; \
	 ${INSTALL} -o ${MANOWN} -c -g ${MANGRP} -m ${MANMODE} popper.0 \
					${LOCALBASE}/man/cat8/qpopper.0 )

.include "../../mk/bsd.pkg.mk"
