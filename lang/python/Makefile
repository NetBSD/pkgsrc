# $NetBSD: Makefile,v 1.4 1998/05/04 19:29:17 tron Exp $
#

DISTNAME=	pyth151
PKGNAME=	python-1.5.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@endicor.com

WRKSRC=		${WRKDIR}/Python-1.5.1
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
		-e 's/@NOREADLINE@/${NOREADLINE}/' -e 's/@NOTK@/${NOTK}/'  \
		-e 's^@PREFIX@^${PREFIX}^g' -e 's^@X11BASE@^${X11BASE}^g'  \
		${FILESDIR}/Setup >${WRKSRC}/Modules/Setup

post-install:
	strip ${PREFIX}/bin/python

.include "../../mk/bsd.pkg.mk"
