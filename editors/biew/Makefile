# $NetBSD: Makefile,v 1.12 2004/10/03 00:14:38 tv Exp $
#

DISTNAME=	biew561
PKGNAME=	biew-5.6.1
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biew/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://biew.sourceforge.net/en/biew.html
COMMENT=	Binary viewer/editor

ONLY_FOR_PLATFORM=	*-*-i386

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/biew-561

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/biew
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/biew
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin_rc/biew.hlp ${PREFIX}/share/biew
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/assembly.skn ${PREFIX}/share/biew
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/golded.skn ${PREFIX}/share/biew
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/insight.skn ${PREFIX}/share/biew
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/standard.skn ${PREFIX}/share/biew
	${INSTALL_DATA} ${WRKSRC}/doc/biew_en.txt ${PREFIX}/share/doc/biew

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
