# $NetBSD: Makefile,v 1.23 2015/04/18 20:43:19 joerg Exp $
#

DISTNAME=		orbital_eunuchs_sniper-1.30
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		http://icculus.org/oes/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://icculus.org/oes/
COMMENT=		Overhead shooting game

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-games-dir=${PREFIX}/libexec

INSTALLATION_DIRS=	share/doc/orbital_eunuchs_sniper

USE_LANGUAGES=		c c++
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	src/snipe2d.in

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64" && ${OPSYS} != "DragonFly"
CPU=			amd64
.elif ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
CPU!=			uname -m
.else
CPU=			${MACHINE_ARCH}
.endif

PLIST_SUBST+=		CPU=${CPU:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/orbital_eunuchs_sniper
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/orbital_eunuchs_sniper

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
