# $NetBSD: Makefile,v 1.27.2.3 2002/08/21 22:42:04 jlam Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp 
#

DISTNAME=	zip-2.3
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.info-zip.org/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/
DISTFILES=	zip23.tar.gz zcrypt29.zip

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.info-zip.org/pub/infozip/Zip.html
COMMENT=	Create/update ZIP files compatible with pkzip

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip

EXTRACT_ONLY=	zip23.tar.gz
MAKEFILE=	unix/Makefile
MAKE_FLAGS=	LOCAL_ZIP="${CFLAGS}" LFLAGS1="${_STRIPFLAG_CC}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=	generic_gcc
.else
ALL_TARGET=	generic
.endif

USE_BUILDLINK2=	# defined

post-extract:
	@cd ${WRKSRC} && unzip -qo ${DISTDIR}/zcrypt29.zip

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} zip.1 ${PREFIX}/man/man1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipcloak.1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipnote.1
	${LN} -f -s zip.1 ${PREFIX}/man/man1/zipsplit.1

.include "../../mk/bsd.pkg.mk"
