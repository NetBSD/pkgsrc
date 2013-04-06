# $NetBSD: Makefile,v 1.17 2013/04/06 12:04:01 rodent Exp $

DISTNAME=	linuxq3apoint-1.32b.x86
PKGNAME=	quake3server-1.32b
PKGREVISION=	2
CATEGORIES=	games net
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/quake3/linux/ \
				http://distfiles.aydogan.net/games/
EXTRACT_SUFX=	.run

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Quake III Arena Dedicated Server for Linux

.include "../../games/quake3server/Makefile.common"

USE_TOOLS+=	bsdtar
EXTRACT_CMD=	${SED} '1,265d' $$extract_file | ${TOOLS_PATH.bsdtar} xzf -
NO_BUILD=	yes

WRKSRC=		${WRKDIR}
BASEDOCDIR=	${PREFIX}/share/doc/lokigames/quake3server
RCD_SCRIPTS=	quake3server

.include "../../mk/bsd.prefs.mk"

SPECIAL_PERMS+=	${Q3ROOTDIR}/q3ded nobody nogroup 0500

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${Q3ROOTDIR}/pb \
		${DESTDIR}${Q3ROOTDIR}/baseq3 \
		${DESTDIR}${Q3ROOTDIR}/missionpack
.for bpak in 1 2 3 4 5 6 7 8
	${INSTALL_DATA} ${WRKSRC}/baseq3/pak${bpak}.pk3 \
		${DESTDIR}${Q3ROOTDIR}/baseq3
.endfor
.for mpak in 1 2 3
	${INSTALL_DATA} ${WRKSRC}/missionpack/pak${mpak}.pk3 \
		${DESTDIR}${Q3ROOTDIR}/missionpack
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/q3ded ${DESTDIR}${Q3ROOTDIR}

.for pb in pbag.so pbcl.so pbsv.so
	${INSTALL_DATA} ${WRKSRC}/pb/${pb} ${DESTDIR}${Q3ROOTDIR}/pb
.endfor

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${BASEDOCDIR}/Docs/LinuxFAQ \
		${DESTDIR}${BASEDOCDIR}/Docs/PunkBuster/admins \
		${DESTDIR}${BASEDOCDIR}/Docs/PunkBuster/players \
		${DESTDIR}${BASEDOCDIR}/pb/htm
.for docs in CHANGES-1.32.txt INSTALL Q3A_EULA.txt README-Id-7-26-01.html \
	README-linux.txt quake3.xpm
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DESTDIR}${BASEDOCDIR}
.endfor
.for faq in INSTALL index.html udp_wide_README.txt udp_wide_broadcast.patch
	${INSTALL_DATA} ${WRKSRC}/Docs/LinuxFAQ/${faq} \
		${DESTDIR}${BASEDOCDIR}/Docs/LinuxFAQ
.endfor
.for admins in index.htm tabout1.gif tadvanced1.gif tbasics1.gif \
	tcommands1.gif tcommands2.gif tenabling1.gif tfaq1.gif tgame1.gif \
	tintro1.gif tlogo.gif tmonitoring1.gif tpbint1.gif tpbsub1.gif \
	tplayer1.gif tquick1.gif tremote1.gif tscreen1.gif tsettings1.gif \
	ttitle1.gif ttoc1.gif tupdating1.gif
	${INSTALL_DATA} ${WRKSRC}/Docs/PunkBuster/admins/${admins} \
		${DESTDIR}${BASEDOCDIR}/Docs/PunkBuster/admins
.endfor
.for players in index.htm sbrowser1.jpg skeyboard1.gif stilde1.gif tabout1.gif \
	tbasics1.gif tbutton1.gif tbutton2.gif tcommands1.gif tcommands2.gif \
	tenabling1.gif tfaq1.gif tfinding1.gif tgame1.gif tintro1.gif \
	tlogo.gif tmonitoring1.gif tname1.gif tpbint1.gif tpbsub1.gif \
	tquick1.gif tremote1.gif tscreen1.gif tsettings1.gif ttaking1.gif \
	ttitle1.gif ttoc1.gif tupdating1.gif tusing1.gif
	${INSTALL_DATA} ${WRKSRC}/Docs/PunkBuster/players/${players} \
		${DESTDIR}${BASEDOCDIR}/Docs/PunkBuster/players
.endfor
.for pbhtm in la001293.htm lc000993.htm ls000993.htm ma001293.htm mc000993.htm \
	ms000993.htm wa001293.htm wc000993.htm ws000993.htm
	${INSTALL_DATA} ${WRKSRC}/pb/htm/${pbhtm} ${DESTDIR}${BASEDOCDIR}/pb/htm
.endfor
	${INSTALL_DATA} ${WRKSRC}/pb/PB_EULA.txt ${DESTDIR}${BASEDOCDIR}/pb

.include "../../mk/bsd.pkg.mk"
