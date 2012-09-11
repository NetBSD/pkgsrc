# $NetBSD: Makefile,v 1.20 2012/09/12 00:24:35 asau Exp $

DISTNAME=	gqmpeg-skins-20030712
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://gqmpeg.sourceforge.net/skins/
DISTFILES+=	\
		2black.tar.gz \
		4thTry.tar.gz \
		AZD.tar.gz \
		Aggressive.blue.tar.gz \
		Agressive.tar.gz \
		BlueSteel.tar.gz \
		CoronerQ.tar.gz \
		FlatLine.tar.gz \
		GTK.tar.gz \
		MoonIce.tar.gz \
		aluminotic-1.1.tar.gz \
		aluminotic.tar.gz \
		bakedbabies.tar.gz \
		blackboard-1.0.tar.gz \
		blue-i_1.tar.gz \
		bubble-mim.tar.gz \
		clean.tar.gz \
		cool.tar.gz \
		fortissimo.2.0.tar.gz \
		fortissimo.tar.gz \
		freeamp.tar.gz \
		gothic.tar.gz \
		gqmpeg-skins-osk-1.0.1.tar.gz \
		gqofol.tar.gz \
		gray.tar.gz \
		grey-black.tar.gz \
		helix.tar.gz \
		hfcool2.tar.gz \
		iMpeg.tar.gz \
		impact.tar.gz \
		info-mod2.tar.gz \
		k-nine.tar.gz \
		kpanel-dock.tar.gz \
		kpanel-normal-horizontal.tar.gz \
		line.tar.gz \
		minialum.tar.gz \
		module.tar.gz \
		sand.tar.gz \
		simplistic.tar.gz \
		skin-bubble-1.0.tar.gz \
		skin-car-preset-1.0.tar.gz \
		skin-circle-1.0.tar.gz \
		skin-e-theme-1.0.tar.gz \
		skin-example-1.2.tar.gz \
		skin-example-d4.tar.gz \
		skin-example2-1.1.tar.gz \
		skin-example3-1.0.tar.gz \
		skin-odometer-1.0.tar.gz \
		skin-paper-1.3.tar.gz \
		skin-pda-1.0.tar.gz \
		skin-pro-player-1.0.tar.gz \
		skin-pro-player2-1.0.tar.gz \
		skin-purple-preset-1.0.tar.gz \
		skin-sg-1.1.tar.gz \
		skin-shiny-blue-1.0.tar.gz \
		skin-silver-1.0.tar.gz \
		skin-slate-alpha.tar.gz \
		skin-wharf.tar.gz \
		spiral.tar.gz \
		swish.tar.gz \
		tattered.19990919.tar.gz \
		tauceti-1.1.tar.gz \
		tildouf-skins.tar.gz \
		ufo.tar.gz \
		wmcool-1.3.tar.gz \
		ye-olde.tar.gz \
		yelojckt.tar.gz \
		zoom-information.tar.gz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://gqmpeg.sourceforge.net/
COMMENT=	Skins for gqmpeg

DEPENDS+=	gqmpeg-[0-9]*:../../audio/gqmpeg-devel

DIST_SUBDIR=	gqmpeg-skins
WRKSRC=		${WRKDIR}
NO_BUILD=	yes

USE_TOOLS+=	gtar

INSTALLATION_DIRS=	share/gqmpeg/skins

do-install:
		for i in ${DISTFILES} ; do \
			${ECHO} unpacking $$i ; \
			${CAT} ${DISTDIR}/${DIST_SUBDIR}/$$i | ( cd ${DESTDIR}${PREFIX}/share/gqmpeg/skins ; \
				    ${GTAR} -zxf - ) ; \
		done
		${FIND} ${DESTDIR}${PREFIX}/share/gqmpeg/skins -type d -print | \
		${XARGS} ${CHMOD} 755
		${FIND} ${DESTDIR}${PREFIX}/share/gqmpeg/skins -type f -print | \
		${XARGS} ${CHMOD} 644
		${FIND} ${DESTDIR}${PREFIX}/share/gqmpeg/skins -name "*~" -print | \
		${XARGS} ${RM} -f
		${CHOWN} -R ${BINOWN}:${BINGRP}  ${DESTDIR}${PREFIX}/share/gqmpeg/skins

.include "../../mk/bsd.pkg.mk"
