# $NetBSD: Makefile,v 1.5 2005/06/06 20:43:52 minskim Exp $

DISTNAME=	winsteng
PKGNAME=	adobeps-win-1.0.6
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.adobe.com/pub/adobe/printerdrivers/win/1.x/
EXTRACT_SUFX=	.exe

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.adobe.com/products/printerdrivers/windows.html
COMMENT=	Adobe PostScript MS Windows drivers for CUPS/Samba

BUILD_DEPENDS+=	cabextract-[0-9]*:../../archivers/cabextract
DEPENDS+=	cups>=1.1.15:../../print/cups

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${LOCALBASE}/bin/cabextract ${DOWNLOADED_DISTFILE}
NO_CONFIGURE=	yes
NO_BUILD=	yes

NTFILES=	ADOBEPS5.DLL ADOBEPSU.DLL ADOBEPSU.HLP DEFPRTR2.PPD
9XFILES=	ADFONTS.MFM ADOBEPS4.DRV ADOBEPS4.HLP ICONLIB.DLL PSMON.DLL
DRIVERDIR=	${PREFIX}/share/cups/drivers

post-extract:
	cd ${WRKSRC}; for dir in WinNT Windows; do			\
		( cd $$dir; for file in *; do				\
			cap=`${ECHO} $$file | ${TR} '[a-z]' '[A-Z]'`;	\
			if [ $$file != $$cap ]; then			\
				${MV} $$file $$cap;			\
			fi;						\
		  done );						\
	done

do-install:
	${INSTALL_DATA_DIR} ${DRIVERDIR}
	for file in ${NTFILES}; do					\
		${INSTALL_DATA} ${WRKSRC}/WinNT/$$file ${DRIVERDIR};	\
	done
	for file in ${9XFILES}; do					\
		${INSTALL_DATA} ${WRKSRC}/Windows/$$file ${DRIVERDIR};	\
	done

.include "../../mk/bsd.pkg.mk"
