# New ports collection makefile for:	qpopper
# Version required:     		2.41beta1
# Date created:				February 12, 1998
# Whom:					Ted Lemon <mellon@fugue.com>
#
# $NetBSD: Makefile,v 1.1 1998/02/13 02:26:03 mellon Exp $
#

DISTNAME=	qpopper2.41beta1
EXTRACT_SUFX=	.tar.Z
CATEGORIES=	mail
MASTER_SITES=   ftp://ftp.qualcomm.com/eudora/servers/unix/qpopper
MASTER_SITE_BACKUPS=

MAINTAINER=     mellon@fugue.com

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

.include <bsd.port.mk>
