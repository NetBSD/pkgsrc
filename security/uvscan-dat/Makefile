# $NetBSD: Makefile,v 1.3 2000/06/27 10:18:05 rh Exp $
#

DISTNAME=	dat-4083
PKGNAME=	uvscan-${DISTNAME}
NO_WRKSUBDIR=	yes
CATEGORIES=	security
MASTER_SITES=	http://download.nai.com/products/datfiles/4.x/nai/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nai.com/asp_set/download/dats/mcafee_4x.asp

NO_BUILD=	YES

MIRROR_DISTFILE=no
RESTRICTED=	"restricted to the license terms set for VirusScan"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}

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
