# $NetBSD: Makefile,v 1.15 1998/12/30 03:20:50 tv Exp $
# FreeBSD Id: Makefile,v 1.14 1997/06/19 05:30:04 ache Exp 
#

DISTNAME=	unzip-5.32
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/
DISTFILES=	unzip532.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cdrom.com/pub/infozip/

MAKEFILE=	unix/Makefile
ALL_TARGET=	unzips
MAKE_FLAGS=	CF="${CFLAGS} -I. -DBSD -Dunix -DUSE_UNSHRINK -DUSE_ZLIB" \
		LF2=-lz

.include "../../mk/bsd.prefs.mk"

.if defined(ZIP_ENCRYPTION)
DISTFILES+=	zcrypt27.zip
EXTRACT_ONLY=	unzip532.tar.gz
RESTRICTED=	crypto
MIRROR_DISTFILE=no

# This bootstrap is ugly, but zcrypt is only shipped as a zipfile.
pre-build:
	@cd ${WRKSRC}; test -f README.CR || ( \
		${ECHO} '*** Building stage 1 of 2--unzip without encryption.' && \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} unzip && \
		./unzip -qo ${DISTDIR}/zcrypt27.zip && \
		${RM} -f *.o unzip )
	@${ECHO} '*** Building stage 2 of 2--unzip with encryption.'
.endif

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} unzip funzip unzipsfx ${PREFIX}/bin
	${LN} -sf unzip ${PREFIX}/bin/zipinfo
	cd ${WRKSRC}/unix && \
		${INSTALL_SCRIPT} zipgrep ${PREFIX}/bin
	cd ${WRKSRC}/unix && \
		${INSTALL_MAN} funzip.1 unzip.1 unzipsfx.1 zipgrep.1 zipinfo.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR}  ${PREFIX}/share/doc/unzip
	cd ${WRKSRC} && \
		${INSTALL_DATA} README WHERE COPYING ${PREFIX}/share/doc/unzip

.include "../../mk/bsd.pkg.mk"
