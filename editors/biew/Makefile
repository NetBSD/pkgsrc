# $NetBSD: Makefile,v 1.10 2004/04/11 08:05:36 snj Exp $
#

DISTNAME=	biew-550
PKGNAME=	biew-5.5.0
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
