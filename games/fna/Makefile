# $NetBSD: Makefile,v 1.18 2024/05/29 16:32:34 adam Exp $

DISTNAME=	FNA-22.05
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=FNA-XNA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fna-xna.github.io/
COMMENT=	Reimplementation of Microsoft XNA Game Studio 4.0 Refresh Libraries
LICENSE=	ms-pl AND gnu-lgpl-v2.1 AND mit

SDL2_CS=	34338dfab2be370b3aa3d3ebbd8bd6cb7f5c1148.tar.gz
FAUDIO=		0a90c02a86495b93b3ce08768d572d3f1cfef3cc.tar.gz
THEORAFILE=	23d47a4c3dc15ec92c147ea27627759c67b03664.tar.gz
NETSTUB=	ebff244074bb3c28aeeb8cf7b383b5a029d7e28d.tar.gz
DISTFILES+=	${DEFAULT_DISTFILES} ${THEORAFILE} ${FAUDIO} ${SDL2_CS} ${NETSTUB}

SITES.${SDL2_CS}+=	${MASTER_SITE_GITHUB:=flibitijibibo/}SDL2-CS/archive/
SITES.${FAUDIO}+=	${MASTER_SITE_GITHUB:=FNA-XNA/}Faudio/archive/
SITES.${THEORAFILE}+=	${MASTER_SITE_GITHUB:=FNA-XNA/}Theorafile/archive/
SITES.${NETSTUB}+=	${MASTER_SITE_GITHUB:=FNA-XNA/}FNA.NetStub/archive/

USE_LANGUAGES=	# none

WRKSRC=	${WRKDIR}/FNA

post-extract:
	${MV} ${WRKDIR}/FNA-${PKGVERSION_NOREV} ${WRKDIR}/FNA
	${MV} ${WRKDIR}/FNA.NetStub-${NETSTUB:S/${EXTRACT_SUFX}//} ${WRKDIR}/FNA.NetStub
	${RM} -r ${WRKSRC}/lib/FAudio ${WRKSRC}/lib/Theorafile ${WRKSRC}/lib/SDL2-CS
	${MV} ${WRKDIR}/FAudio-${FAUDIO:S/${EXTRACT_SUFX}//} ${WRKSRC}/lib/FAudio
	${MV} ${WRKDIR}/Theorafile-${THEORAFILE:S/${EXTRACT_SUFX}//} ${WRKSRC}/lib/Theorafile
	${MV} ${WRKDIR}/SDL2-CS-${SDL2_CS:S/${EXTRACT_SUFX}//} ${WRKSRC}/lib/SDL2-CS

# need to rm bin,obj before FNA.sln to build with FNA.Settings.props
do-build:
	xbuild /p:Configuration=Release ${WRKSRC}/abi/Microsoft.Xna.Framework.sln
	${RM} -rf ${WRKSRC}/bin ${WRKSRC}/obj
	xbuild /p:Configuration=Release ${WRKSRC}/FNA.sln

INSTALLATION_DIRS=	share/FNA
do-install:
	mkdir -p ${DESTDIR}${PREFIX}/share/FNA
	${INSTALL_DATA} ${WRKSRC}/bin/Release/FNA.dll ${DESTDIR}${PREFIX}/share/FNA/
	${INSTALL_DATA} \
		${WRKSRC}/abi/bin/Release/FNA.NetStub.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.Game.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.GamerServices.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.Graphics.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.Input.Touch.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.Net.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.Storage.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.Video.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.Xact.dll \
		${WRKSRC}/abi/bin/Release/Microsoft.Xna.Framework.dll \
		${DESTDIR}${PREFIX}/share/FNA/
	${INSTALL_DATA} ${FILESDIR}/FNA.dll.config ${DESTDIR}${PREFIX}/share/FNA/

.include "../../graphics/mojoshader/buildlink3.mk"
.include "../../graphics/fna3d/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../audio/faudio/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
