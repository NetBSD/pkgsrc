# $NetBSD: Makefile,v 1.35 2020/03/20 11:57:46 nia Exp $

DISTNAME=	aview-1.3.0rc1
PKGNAME=	aview-1.3.0.1
PKGREVISION=	17
CATEGORIES=	graphics converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aa-project/}

MAINTAINER=	salo@Xtrmntr.org
HOMEPAGE=	http://aa-project.sourceforge.net/aview/
COMMENT=	ASCII Art image viewer
LICENSE=	gnu-gpl-v2

DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm

CONFLICTS+=	aview-x11-[0-9]*

PLIST_SRC=	${WRKDIR}/PLIST

WRKSRC=		${WRKDIR}/aview-1.3.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	mktemp:run

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		programs
SUBST_STAGE.programs=	pre-configure
SUBST_MESSAGE.programs=	Filling @placeholders@.
SUBST_FILES.programs=	Makefile.in
.if (${MACHINE_ARCH} == "i386")
SUBST_SED.programs+=	-e 's,@BIN_PROGRAMS@,aview aaflip,g'
.else
SUBST_SED.programs+=	-e 's,@BIN_PROGRAMS@,aview,g'
.endif

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	asciiview

INSTALLATION_DIRS=	share/doc/aview

post-install:
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/aview/
	${INSTALL_DATA} ${WRKSRC}/TODO ${DESTDIR}${PREFIX}/share/doc/aview/
.if (${MACHINE_ARCH} == "i386")
	${INSTALL_PROGRAM} ${WRKSRC}/aaflip ${DESTDIR}${PREFIX}/bin/
	@${ECHO} bin/aaflip >>${PLIST_SRC}
.endif

.include "../../graphics/aalib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
