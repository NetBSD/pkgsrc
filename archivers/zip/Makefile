# $NetBSD: Makefile,v 1.13 1998/08/20 15:16:38 tsarna Exp $
# FreeBSD Id: Makefile,v 1.10 1997/04/27 16:06:15 ache Exp 
#

DISTNAME=	zip-2.2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/infozip/src/ \
		ftp://ftp.icce.rug.nl/infozip/src/
DISTFILES=	zip22.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cdrom.com/pub/infozip/

MAKEFILE=	unix/Makefile
MAKE_FLAGS=	LOCAL_ZIP="${CFLAGS}"
ALL_TARGET=	generic

.include "../../mk/bsd.prefs.mk"

.if defined(ZIP_ENCRYPTION)
DISTFILES+=	zcrypt27.zip
EXTRACT_ONLY=	zip22.tar.gz
BUILD_DEPENDS=	unzip:../../archivers/unzip
RESTRICTED=	crypto
MIRROR_DISTFILE=no

post-extract:
	@cd ${WRKSRC} && unzip -qo ${DISTDIR}/zcrypt27.zip
.endif

do-install:
	cd ${WRKSRC} && \
	    ${INSTALL_PROGRAM} zip zipnote zipsplit zipcloak ${PREFIX}/bin
	cd ${WRKSRC}/man && \
	    ${INSTALL_MAN} zip.1 ${PREFIX}/man/man1
	ln -fs zip.1 ${PREFIX}/man/man1/zipcloak.1
	ln -fs zip.1 ${PREFIX}/man/man1/zipnote.1
	ln -fs zip.1 ${PREFIX}/man/man1/zipsplit.1

.include "../../mk/bsd.pkg.mk"
