# $NetBSD: Makefile,v 1.4 2021/09/08 21:05:05 nia Exp $

GITHUB_PROJECT=	FNA
GITHUB_TAG=	21.01
DISTNAME=	21.01
PKGNAME=	${GITHUB_PROJECT:tl}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=FNA-XNA/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fna-xna.github.io/
COMMENT=	Reimplementation of Microsoft XNA Game Studio 4.0 Refresh Libraries
LICENSE=	ms-pl AND gnu-lgpl-v2.1 AND mit


SDL2_CS=	1e01bc8eebb501bf6df24ec98784c32843308e0a.tar.gz
FAUDIO=		0f3f1e6df74da481d466dd97aa4345ea9fe56ca4.tar.gz
THEORAFILE=	0c5504658a3108919e53b625287786a87529de42.tar.gz
NETSTUB=	ebff244074bb3c28aeeb8cf7b383b5a029d7e28d.tar.gz
DISTFILES+=	${DEFAULT_DISTFILES} ${THEORAFILE} ${FAUDIO} ${SDL2_CS} ${NETSTUB}

SITES.${SDL2_CS}+=	${MASTER_SITE_GITHUB:=flibitijibibo/}SDL2-CS/archive/
SITES.${FAUDIO}+=	${MASTER_SITE_GITHUB:=FNA-XNA/}Faudio/archive/
SITES.${THEORAFILE}+=	${MASTER_SITE_GITHUB:=FNA-XNA/}Theorafile/archive/
SITES.${NETSTUB}+=	${MASTER_SITE_GITHUB:=FNA-XNA/}FNA.NetStub/archive/

WRKSRC=		${WRKDIR}/FNA-21.01
USE_LANGUAGES=	# none

post-extract:
	${LN} -sf ${WRKDIR}/FNA.NetStub-${NETSTUB:S/${EXTRACT_SUFX}//} ${WRKDIR}/FNA.NetStub
	${LN} -sf ${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME} ${WRKDIR}/FNA
	${RM} -r ${WRKSRC}/lib/FAudio ${WRKSRC}/lib/Theorafile ${WRKSRC}/lib/SDL2-CS
	${LN} -sf ${WRKDIR}/FAudio-${FAUDIO:S/${EXTRACT_SUFX}//} ${WRKSRC}/lib/FAudio
	${LN} -sf ${WRKDIR}/Theorafile-${THEORAFILE:S/${EXTRACT_SUFX}//} ${WRKSRC}/lib/Theorafile
	${LN} -sf ${WRKDIR}/SDL2-CS-${SDL2_CS:S/${EXTRACT_SUFX}//} ${WRKSRC}/lib/SDL2-CS


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
