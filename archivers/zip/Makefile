# $NetBSD: Makefile,v 1.26 2001/11/29 01:12:25 hubertf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp 
#

DISTNAME=	zip-2.3
PKGREVISION=	1
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
MAKE_FLAGS=	LOCAL_ZIP="${CFLAGS}"
ALL_TARGET=	generic

USE_BUILDLINK_ONLY=	# defined

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
