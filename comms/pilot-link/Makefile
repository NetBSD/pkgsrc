# New ports collection makefile for:	pilot-link
# Version required:	0.8.11
# Date created:		28 December 1996
# Whom:			sommerfeld@alum.mit.edu
#
# $NetBSD: Makefile,v 1.1 1998/03/17 03:02:31 sommerfe Exp $
#

DISTNAME=	pilot-link.0.8.11
CATEGORIES=	comms
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/
MAINTAINER=	sommerfeld@alum.mit.edu

STRIPFLAG=
GNU_CONFIGURE=yes

# use "default" configure because overriding INSTALL_PROGRAM does the
# wrong thing for libtool-based packages like pilot-link...

do-configure:
	@(cd ${WRKSRC} && CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})


.include <bsd.port.mk>


