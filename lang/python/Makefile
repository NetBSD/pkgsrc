# New ports collection makefile for:	python
# Version required:	1.5
# Date created:		1 January 1998
# Whom:			tsarna@endicor.com
#
# $NetBSD: Makefile,v 1.2 1998/02/01 01:54:43 tron Exp $
#

DISTNAME=	python1.5
PKGNAME=	python-1.5
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/

MAINTAINER=	tsarna@endicor.com

WRKSRC=		${WRKDIR}/Python-1.5
GNU_CONFIGURE=	yes
MAKE_FLAGS+=	'OPT=${CFLAGS}'
MAN1=		python.1

# Handle the module setup file:
#   - disable some modules on 64 bit platforms
#   - handle machines with no dynamic loader

.if ${MACHINE_ARCH} == "alpha"
NO64BIT=\#
.endif
.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "alpha"
NOSHARED=\#
.endif

post-configure:
	${SED} -e 's/@NO64BIT@/${NO64BIT}/' -e 's/@NOSHARED@/${NOSHARED}/' \
		${FILESDIR}/Setup >${WRKSRC}/Modules/Setup

post-install:
	strip ${PREFIX}/bin/python

.include <bsd.port.mk>
