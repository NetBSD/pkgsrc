# $NetBSD: Makefile,v 1.9 1998/08/20 15:17:08 tsarna Exp $
#

DISTNAME=	pyth151
PKGNAME=	python-1.5.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www.python.org/1.5/patches-1.5.1/
PATCHFILES= 	freeze.1.txt _tkinter.1.txt configure.1.txt \
		object.1.txt parsermodule.1.txt zlibmodule.1.txt \
		string.1.txt bltinmodule.1.txt timemodule.1.txt \
		fileobject.1.txt urllib.1.txt pcre.1.txt \
		configure.2.txt imaplib.1.txt urllib.2.txt \
		sgmllib.1.txt bltinmodule.2.txt ceval.1.txt gzip.1.txt \
		imaplib.2.txt import.1.txt imaplib.3.txt \
		stringobject.1.txt sgmllib.2.txt

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/

WRKSRC=		${WRKDIR}/Python-1.5.1
GNU_CONFIGURE=	yes
MAKE_FLAGS+=	'OPT=${CFLAGS}'

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
