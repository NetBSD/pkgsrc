# $NetBSD: Makefile,v 1.3 2001/02/25 04:17:44 hubertf Exp $
#

DISTNAME=	biew-520
PKGNAME=	biew-5.2.0
CATEGORIES=	editors
MASTER_SITES=	ftp://biew.sourceforge.net/pub/biew/5.x/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://biew.sourceforge.net/en/biew.html
COMMENT=	Binary viewer/editor

DEPENDS+=	libslang-*:../../devel/libslang

ONLY_FOR_PLATFORM=	*-*-i386
USE_GMAKE=	YES
MAKEFILE=	makefile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/biew/ ${PREFIX}/share/doc/biew/
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin_rc/biew.hlp ${PREFIX}/share/biew/
	${INSTALL_DATA} ${WRKSRC}/bin_rc/standard.skn ${PREFIX}/share/biew/
	${INSTALL_DATA} ${WRKSRC}/bin_rc/assembly.skn ${PREFIX}/share/biew/
	${INSTALL_DATA} ${WRKSRC}/doc/biew_en.txt ${PREFIX}/share/doc/biew/

.include "../../mk/bsd.pkg.mk"
