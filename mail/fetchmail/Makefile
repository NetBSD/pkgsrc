# New ports collection makefile for:	fetchmail
# Version required:     4.3.6
# Date created:		26 Oct 1996
# Whom:			Ville Eerola <ve@sci.fi>
#
# $NetBSD: Makefile,v 1.2 1998/02/28 11:35:39 tron Exp $
# $FreeBSD Id: Makefile,v 1.55 1998/01/29 17:13:07 ache Exp
#

DISTNAME=       fetchmail-4.3.6
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/

MAINTAINER=	ve@sci.fi

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  LDFLAGS="${CFLAGS}"
MAN1=		fetchmail.1

.if exists(/usr/lib/libkrb.a) && (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CONFIGURE_ARGS += --with-kerberos=/usr/include/kerberosIV
.endif

FDOC=   ${PREFIX}/share/doc/fetchmail

post-extract:
	${RM} -f ${WRKSRC}/md5.h

post-install:
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   sample.rcfile FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include <bsd.port.mk>
