# $NetBSD: Makefile,v 1.16 1999/12/13 13:15:22 rh Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp 
#

DISTNAME=	zip-2.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/
DISTFILES=	zip23.tar.gz

MAINTAINER=	wiz@danbala.tuwien.ac.at
HOMEPAGE=	http://www.cdrom.com/pub/infozip/

MAKEFILE=	unix/Makefile
MAKE_FLAGS=	LOCAL_ZIP="${CFLAGS}"
ALL_TARGET=	generic

BUILD_DEFS+=	ZIP_ENCRYPTION

.include "../../mk/bsd.prefs.mk"

.if defined(ZIP_ENCRYPTION)
DISTFILES+=	zcrypt28.zip
EXTRACT_ONLY=	zip23.tar.gz
BUILD_DEPENDS=	unzip:../../archivers/unzip
RESTRICTED=	crypto
MIRROR_DISTFILE=no

post-extract:
	@cd ${WRKSRC} && unzip -qo ${DISTDIR}/zcrypt28.zip
.endif

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} zip.1 ${PREFIX}/man/man1
	ln -f -s zip.1 ${PREFIX}/man/man1/zipcloak.1
	ln -f -s zip.1 ${PREFIX}/man/man1/zipnote.1
	ln -f -s zip.1 ${PREFIX}/man/man1/zipsplit.1

.include "../../mk/bsd.pkg.mk"
