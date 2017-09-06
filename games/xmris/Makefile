# $NetBSD: Makefile,v 1.19 2017/09/06 10:40:28 wiz Exp $

DISTNAME=		xmris.4.0.5
PKGNAME=		xmris-4.05
PKGREVISION=		3
CATEGORIES=		games x11
#MASTER_SITES=		http://www.planetfall.pwp.blueyonder.co.uk/xmris/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.planetfall.pwp.blueyonder.co.uk/xmris/
COMMENT=		Version of the Mr Do video arcade game for X
LICENSE=		gnu-gpl-v2

USE_IMAKE=		yes
USE_GAMESGROUP=		yes
NO_INSTALL_MANPAGES=	yes
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-configure
SUBST_FILES.varbase=	Imakefile
SUBST_VARS.varbase=	VARBASE

post-install:
	${INSTALL_MAN} ${WRKSRC}/xmris.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xmris.6
	${LN} -fs xmris.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xmsit.6
	${INSTALL_MAN} ${WRKSRC}/xmred.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xmred.6

SPECIAL_PERMS+=		bin/xmris ${SETGID_GAMES_PERMS}
# require to write lock files
REQD_DIRS_PERMS+=	${VARBASE}/games/xmris ${GAMEDIR_PERMS}
REQD_FILES_PERMS+=	/dev/null ${VARBASE}/games/xmris/xmris.score ${GAMEDATA_PERMS}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
