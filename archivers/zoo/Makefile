# New ports collection makefile for:    zoo
# Version required:     2.10pl1
# Date created:         18 October 1994
# Whom:                 jmz
#
# $NetBSD: Makefile,v 1.3 1997/11/18 13:10:49 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/08/10 22:31:36 fenner Exp 
#

DISTNAME=       zoo-2.10pl1
PKGNAME=	zoo-2.10.1
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/

MAINTAINER=	jmz@FreeBSD.org

NO_WRKSUBDIR=	yes
ALL_TARGET=     bsdansi
MAKEFILE=       makefile
MAKE_ENV+=	COPY=${COPY} STRIP=${STRIP} \
		BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}
MAN1=		fiz.1 zoo.1

.include <bsd.port.mk>
