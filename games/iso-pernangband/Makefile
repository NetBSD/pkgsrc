# $NetBSD: Makefile,v 1.13 2003/12/13 20:14:26 ben Exp $
#

DISTNAME=		iso-pern_src-0_2_6
PKGNAME=		iso-pernangband-0.2.6
PKGREVISION=		2
WRKSRC=			${WRKDIR}/iso-pern_src/src
CATEGORIES=		games
MASTER_SITES=		http://www.simugraph.com/simutrans/data/

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://www.isoband.cjb.net/
COMMENT=		Isometric (pseudo 3D) view for Angband

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_X11=		yes

post-patch:
	${CP} ${WRKSRC}/simugraph/simgraph.c ${WRKSRC}/simugraph/simgraph.c.orig
	${SED}	-e "s,\./,${PREFIX}/share/iso-pernangband/," \
		-e "s,\([a-z0-9]*\.pak\),${PREFIX}/share/iso-pernangband/\1," \
		<${WRKSRC}/simugraph/simgraph.c.orig \
		>${WRKSRC}/simugraph/simgraph.c

	# change keymap to match isometric view, much more convenient
	${CP}	${WRKSRC}/../lib/user/pref-sdl.prf \
		${WRKSRC}/../lib/user/pref-sdl.prf.orig
	${SED}	-e 's,1$$,z,' -e 's,4$$,1,' -e 's,7$$,4,' \
		-e 's,8$$,7,' -e 's,9$$,8,' -e 's,6$$,9,' \
		-e 's,3$$,6,' -e 's,2$$,3,' -e 's,z$$,2,' \
		<${WRKSRC}/../lib/user/pref-sdl.prf.orig \
		>${WRKSRC}/../lib/user/pref-sdl.prf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/iso-pernangband
	${CP} -R ${WRKSRC}/../lib/* ${PREFIX}/share/iso-pernangband
	${INSTALL_DATA} \
		${WRKSRC}/../daten.pak \
		${WRKSRC}/../daten2.pak \
		${WRKSRC}/../draw.fnt \
		${PREFIX}/share/iso-pernangband
	${CHOWN} -R bin:games ${PREFIX}/share/iso-pernangband
	${CHMOD} -R 0664 ${PREFIX}/share/iso-pernangband
	${FIND} ${PREFIX}/share/iso-pernangband -type d | ${XARGS} ${CHMOD} 0775
	${INSTALL} -c -s -o bin -g games -m 2755 \
		${WRKSRC}/testing \
		${PREFIX}/bin/iso-pernangband

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
