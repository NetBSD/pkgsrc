# $NetBSD: Makefile,v 1.7 2001/02/17 17:50:14 wiz Exp $
#

DISTNAME=		vlnx407e
PKGNAME=		uvscan-4.07e
NO_WRKSUBDIR=		YES
CATEGORIES=		security
MASTER_SITES=		http://download.mcafee.com/products/evaluation/virusscan/english/unix/linux/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.nai.com/asp_set/buy_try/try/products_evals.asp
COMMENT=		evaluation version of a DOS/Windows file virus scanner

DEPENDS+=		suse_libc5>=6.1:../../emulators/suse_libc5
DEPENDS+=		uvscan-dat>=4080:../../security/uvscan-dat

ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_BUILD=		YES

LICENSE=		shareware
RESTRICTED=		"restrictive 30 day evaluation license"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

CHECK_SHLIBS=		no

do-configure:
	${SED} <${FILESDIR}/uvscan.sh >${WRKSRC}/uvscan.sh \
		-e 's:@@PREFIX@@:${PREFIX}:g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${PREFIX}/libexec/uvscan
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan.sh ${PREFIX}/bin/uvscan
.for file in license.dat messages.dat
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/libexec/uvscan
.endfor
.for file in unx47uag.pdf license.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/uvscan
.endfor

.include "../../mk/bsd.pkg.mk"
