# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:29 agc Exp $
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

.include "../../mk/bsd.pkg.mk"
