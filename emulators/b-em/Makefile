# $NetBSD: Makefile,v 1.11 2023/09/15 16:11:13 reinoud Exp $

DISTNAME=	b-em-2.2
PKGNAME=	b-em-20230915
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=stardot/}
GITHUB_TAG=	464bb82239e31862e87b39b257d63086861b99e5
EXTRACT_SUFX=	.zip

MAINTAINER=	reinoud@NetBSD.org
HOMEPAGE=	https://github.com/stardot/b-em
COMMENT=	Freeware Acorn BBC Micro Emulator with 2nd processors
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake aclocal automake autoconf

WRKSRC=		${WRKDIR}/b-em-${GITHUB_TAG}/
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

BEMDATADIR=	${PREFIX}/share/b-em/

post-extract:
	cd ${WRKSRC} && mkdir etc && aclocal && autoconf && automake -acf

do-install:
	${INSTALL} -d ${DESTDIR}${PREFIX}/bin
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/roms
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/fonts
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/discs
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/tapes
	${INSTALL} -d ${DESTDIR}${BEMDATADIR}/ddnoise
	${INSTALL_PROGRAM} ${WRKSRC}/b-em ${DESTDIR}${PREFIX}/bin/b-em
	${CP}    ${WRKSRC}/cmos*.bin ${DESTDIR}${BEMDATADIR}/
	${CP}    ${WRKSRC}/b-em.cfg ${DESTDIR}${BEMDATADIR}/
	${CP} -R ${WRKSRC}/roms/*    ${DESTDIR}${BEMDATADIR}/roms
	${CP} -R ${WRKSRC}/fonts/*    ${DESTDIR}${BEMDATADIR}/fonts
	${CP} -R ${WRKSRC}/discs/*   ${DESTDIR}${BEMDATADIR}/discs
	${CP} -R ${WRKSRC}/tapes/*   ${DESTDIR}${BEMDATADIR}/tapes
	${CP} -R ${WRKSRC}/ddnoise/* ${DESTDIR}${BEMDATADIR}/ddnoise
	${FIND} ${DESTDIR}${BEMDATADIR} -type f -exec chmod 644 {} \;

BUILDLINK_API_DEPENDS.allegro+=	allegro>=4.4.2nb2
.include "../../devel/allegro5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
