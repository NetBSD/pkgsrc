# $NetBSD: Makefile,v 1.1.1.1 2000/06/05 12:01:24 rh Exp $
#

DISTNAME=		vlnx407e
PKGNAME=		uvscan-4.07e
NO_WRKSUBDIR=		YES
CATEGORIES=		security
MASTER_SITES=		http://download.mcafee.com/products/evaluation/virusscan/english/unix/linux/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.nai.com/asp_set/buy_try/try/products_evals.asp

DEPENDS+=		suse_linux>=6.1:../../emulators/suse_linux
DEPENDS+=		uvscan-dat>=4080:../../security/uvscan-dat

ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_BUILD=		YES

MIRROR_DISTFILE=	no
LICENSE=		shareware
RESTRICTED=		"restrictive 30 day evaluation license"
NO_PACKAGE=		${RESTRICTED}
NO_CDROM=		${RESTRICTED}

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
