# $NetBSD: Makefile,v 1.7 1998/06/30 06:55:46 hubertf Exp $
#

DISTNAME=	qpopper2.5
PKGNAME=	qpopper-2.5
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.qualcomm.com/eudora/servers/unix/popper/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     mellon@fugue.com

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
