# $NetBSD: Makefile,v 1.15 2001/05/14 11:54:54 rh Exp $
#

DISTNAME=	dat-4137
PKGNAME=	uvscan-${DISTNAME}
NO_WRKSUBDIR=	yes
CATEGORIES=	security
MASTER_SITES=	http://download.nai.com/products/datfiles/4.x/nai/ \
		http://gd.tuwien.ac.at/pc/nai/antivirus/datfiles/4.x/ \
		ftp://ftp.tuwien.ac.at/pc/nai/antivirus/datfiles/4.x/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nai.com/asp_set/download/dats/mcafee_4x.asp
COMMENT=	AntiVirus DAT file for uvscan

NO_BUILD=	YES

RESTRICTED=	"restricted to the license terms set for VirusScan"
NO_BIN_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}

do-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:g' \
		<${FILESDIR}/update_dat >${WRKDIR}/update_dat

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/uvscan
.for file in clean.dat internet.dat names.dat scan.dat
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/libexec/uvscan
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/uvscan
.for file in reseller.txt readme.txt packing.lst
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/uvscan
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/update_dat ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
