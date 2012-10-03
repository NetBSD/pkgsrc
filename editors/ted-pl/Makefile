# $NetBSD: Makefile,v 1.13 2012/10/03 11:43:45 asau Exp $

DISTNAME=	Ted_pl_PL
PKGNAME=	ted-pl-2.16
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	Polish spelling dictionary for the Ted word processor

DEPENDS+=	ted>=2.6:../../editors/ted

WRKSRC=		${WRKDIR}
USE_X11BASE=	YES

DIST_SUBDIR=	Ted-2.16
NO_BUILD=	YES

INSTALLATION_DIRS=	share/Ted/ind

post-extract:
		cd ${WRKSRC};tar xvf Ted/ad/Ted_pl_PL.ad.tar

post-patch:
		${ECHO} "Ted*fontList:		-adobe-helvetica-medium-r-*-*-*-100-*-*-*-*-iso8859-2" \
		>>${WRKSRC}/usr/lib/X11/pl_PL/app-defaults/Ted
		${ECHO} "Ted.documentFileName:	${PREFIX}/share/doc/Ted/TedDocument-en_US.rtf" \
		>>${WRKSRC}/usr/lib/X11/pl_PL/app-defaults/Ted

do-install:
	${INSTALL_DATA} ${WRKSRC}/ind/Polish.ind \
		${DESTDIR}${PREFIX}/share/Ted/ind
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/X11/app-defaults/pl_PL
	${INSTALL_DATA} ${WRKSRC}/usr/lib/X11/pl_PL/app-defaults/Ted \
		${DESTDIR}${PREFIX}/lib/X11/app-defaults/pl_PL/

.include "../../mk/bsd.pkg.mk"
