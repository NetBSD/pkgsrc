# $NetBSD: Makefile,v 1.2 2002/01/30 12:05:27 agc Exp $
#

DISTNAME=	aview-1.3.0rc1
PKGNAME=	aview-1.3.0.1
PKGREVISION=	1
CATEGORIES=	graphics converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	salo@Xtrmntr.org
HOMEPAGE=	http://aa-project.sourceforge.net/aview/
COMMENT=	ASCII Art image viewer

CONFLICTS+=	aview-x11-[0-9]*

WRKSRC=		${WRKDIR}/aview-1.3.0
PLIST_SRC=	${WRKDIR}/PLIST

GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
USE_BUILDLINK_ONLY=	yes

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
FILES_SUBST= BIN_PROGRAMS="aview aaflip"
.else
FILES_SUBST= BIN_PROGRAMS="aview"
.endif
FILES_SUBST_SED=  ${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/-e s!@/}

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

.include "../../graphics/aalib/buildlink.mk"
.include "../../graphics/netpbm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
