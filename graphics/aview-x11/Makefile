# $NetBSD: Makefile,v 1.10 2004/10/03 00:14:48 tv Exp $
#

DISTNAME=	aview-1.3.0rc1
PKGNAME=	aview-x11-1.3.0.1
PKGREVISION=	3
CATEGORIES=	graphics converters x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	salo@Xtrmntr.org
HOMEPAGE=	http://aa-project.sourceforge.net/aview/
COMMENT=	ASCII Art image viewer with X11 support

CONFLICTS+=	aview-[0-9]*

PLIST_SRC=	${WRKDIR}/PLIST

WRKSRC=		${WRKDIR}/aview-1.3.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes
USE_X11=	yes

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
FILES_SUBST+= BIN_PROGRAMS="aview aaflip"
.else
FILES_SUBST+= BIN_PROGRAMS="aview"
.endif

pre-configure:
	@${SED} ${FILES_SUBST_SED} ${WRKSRC}/Makefile.in > ${WRKDIR}/Makefile.in
	@${MV} ${WRKDIR}/Makefile.in ${WRKSRC}/

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/README* ${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/aview/
.if (${MACHINE_ARCH} == "i386")
	${INSTALL_PROGRAM} ${WRKSRC}/aaflip ${PREFIX}/bin/
	@${ECHO} bin/aaflip >>${PLIST_SRC}
.endif

.include "../../graphics/aalib-x11/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
