# $NetBSD: Makefile,v 1.5 2004/01/20 12:14:06 agc Exp $

DISTNAME=	Ted_pl_PL
PKGNAME=	ted-pl-2.14
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Polish spelling dictionary for the Ted word processor

DEPENDS+=       ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}
USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.14
NO_BUILD=	YES

post-extract:
		cd ${WRKSRC};tar xvf Ted/ad/Ted_pl_PL.ad.tar

post-patch:
		${ECHO} "Ted*fontList:		-adobe-helvetica-medium-r-*-*-*-100-*-*-*-*-iso8859-2" \
		>>${WRKSRC}/usr/lib/X11/pl_PL/app-defaults/Ted
		${ECHO} "Ted.documentFileName:	${PREFIX}/share/doc/Ted/TedDocument-en_US.rtf" \
		>>${WRKSRC}/usr/lib/X11/pl_PL/app-defaults/Ted

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Polish.ind ${PREFIX}/share/Ted/ind
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/app-defaults/pl_PL
	${INSTALL_DATA} ${WRKSRC}/usr/lib/X11/pl_PL/app-defaults/Ted ${PREFIX}/lib/X11/app-defaults/pl_PL/

.include "../../mk/bsd.pkg.mk"
