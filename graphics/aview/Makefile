# $NetBSD: Makefile,v 1.15 2006/01/19 01:40:55 joerg Exp $
#

DISTNAME=	aview-1.3.0rc1
PKGNAME=	aview-1.3.0.1
PKGREVISION=	5
CATEGORIES=	graphics converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	salo@Xtrmntr.org
HOMEPAGE=	http://aa-project.sourceforge.net/aview/
COMMENT=	ASCII Art image viewer

CONFLICTS+=	aview-x11-[0-9]*

PLIST_SRC=	${WRKDIR}/PLIST

WRKSRC=		${WRKDIR}/aview-1.3.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		programs
SUBST_FILES.programs=	Makefile.in
SUBST_STAGE.programs=	post-patch

.if (${MACHINE_ARCH} == "i386")
SUBST_SED.programs+=	-e 's,@BIN_PROGRAMS@,aview aaflip,g'
.else
SUBST_SED.programs+=	-e 's,@BIN_PROGRAMS@,aview,g'
.endif

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

.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
