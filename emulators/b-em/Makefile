# $NetBSD: Makefile,v 1.2 2012/07/27 16:08:52 wiz Exp $
#

DISTNAME=	B-emv2.1aLinux
PKGNAME=	b-em-2.1a
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://b-em.bbcmicro.com/

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	http://b-em.bbcmicro.com/
COMMENT=	Freeware Acorn BBC Micro Emulator with 2nd processors

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

BEMDATADIR=	${PREFIX}/share/b-em/

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing non-existing paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/linux.c src/win.c
SUBST_SED.paths=	-e 's,@BEMDATADIR@,${BEMDATADIR},g'

do-install:
	${INSTALL} -d ${DESTDIR}${PREFIX}/bin
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/roms
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/discs
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/tapes
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/ddnoise
	${INSTALL_PROGRAM} ${WRKSRC}/b-em ${DESTDIR}${PREFIX}/bin/b-em
	${CP}    ${WRKSRC}/cmos*.bin ${DESTDIR}${BEMDATADIR}/
	${CP} -R ${WRKSRC}/roms/*    ${DESTDIR}${BEMDATADIR}/roms
	${CP} -R ${WRKSRC}/discs/*   ${DESTDIR}${BEMDATADIR}/discs
	${CP} -R ${WRKSRC}/tapes/*   ${DESTDIR}${BEMDATADIR}/tapes
	${CP} -R ${WRKSRC}/ddnoise/* ${DESTDIR}${BEMDATADIR}/ddnoise
	${FIND} ${DESTDIR}${BEMDATADIR} -type f -exec chmod 644 {} \;

.include "../../devel/allegro/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
