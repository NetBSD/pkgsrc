# $NetBSD: Makefile,v 1.4 2005/05/02 23:02:06 reed Exp $

DISTNAME=	linuxq3apoint-1.32b.x86
PKGNAME=	quake3server-1.32b
PKGREVISION=	1
CATEGORIES=	games net
MASTER_SITES=	ftp://ftp.bluesnews.com/idstuff/quake3/linux/ \
		ftp://ftp.idsoftware.com/idstuff/quake3/linux/
EXTRACT_SUFX=	.run

MAINTAINER=	david@silicium.ath.cx
COMMENT=	Quake III Arena Dedicated Server for Linux

.include "../../games/quake3server/Makefile.common"

ONLY_FOR_PLATFORM=	NetBSD-*-i386
EXTRACT_CMD=    ${SED} '1,265d' ${DOWNLOADED_DISTFILE} | ${GTAR} xzf -
WRKSRC=		${WRKDIR}
BASEDOCDIR=	${PREFIX}/share/doc/lokigames/quake3server
USE_PKGINSTALL=	YES
RCD_SCRIPTS=	quake3server

do-install:
	${INSTALL_DATA_DIR} ${Q3ROOTDIR}/pb ${Q3ROOTDIR}/baseq3 \
		${Q3ROOTDIR}/missionpack
.for bpak in 1 2 3 4 5 6 7 8
	${INSTALL_DATA} ${WRKSRC}/baseq3/pak${bpak}.pk3 \
		${Q3ROOTDIR}/baseq3
.endfor
.for mpak in 1 2 3
	${INSTALL_DATA} ${WRKSRC}/missionpack/pak${mpak}.pk3 \
		${Q3ROOTDIR}/missionpack
.endfor
	${INSTALL} -c -o nobody -g nogroup -m 500 ${WRKSRC}/bin/x86/q3ded \
		${Q3ROOTDIR}

.for pb in pbag.so pbcl.so pbsv.so
	${INSTALL_DATA} ${WRKSRC}/pb/${pb} ${Q3ROOTDIR}/pb
.endfor

post-install:
	${INSTALL_DATA_DIR} ${BASEDOCDIR}/Docs/LinuxFAQ \
		${BASEDOCDIR}/Docs/PunkBuster/admins \
		${BASEDOCDIR}/Docs/PunkBuster/players \
		${BASEDOCDIR}/pb/htm
.for docs in CHANGES-1.32.txt INSTALL Q3A_EULA.txt README-Id-7-26-01.html \
	README-linux.txt quake3.xpm
	${INSTALL_DATA} ${WRKSRC}/${docs} ${BASEDOCDIR}
.endfor
.for faq in INSTALL index.html udp_wide_README.txt udp_wide_broadcast.patch
	${INSTALL_DATA} ${WRKSRC}/Docs/LinuxFAQ/${faq} \
		${BASEDOCDIR}/Docs/LinuxFAQ
.endfor
.for admins in index.htm tabout1.gif tadvanced1.gif tbasics1.gif \
	tcommands1.gif tcommands2.gif tenabling1.gif tfaq1.gif tgame1.gif \
	tintro1.gif tlogo.gif tmonitoring1.gif tpbint1.gif tpbsub1.gif \
	tplayer1.gif tquick1.gif tremote1.gif tscreen1.gif tsettings1.gif \
	ttitle1.gif ttoc1.gif tupdating1.gif
	${INSTALL_DATA} ${WRKSRC}/Docs/PunkBuster/admins/${admins} \
		${BASEDOCDIR}/Docs/PunkBuster/admins
.endfor
.for players in index.htm sbrowser1.jpg skeyboard1.gif stilde1.gif tabout1.gif \
	tbasics1.gif tbutton1.gif tbutton2.gif tcommands1.gif tcommands2.gif \
	tenabling1.gif tfaq1.gif tfinding1.gif tgame1.gif tintro1.gif \
	tlogo.gif tmonitoring1.gif tname1.gif tpbint1.gif tpbsub1.gif \
	tquick1.gif tremote1.gif tscreen1.gif tsettings1.gif ttaking1.gif \
	ttitle1.gif ttoc1.gif tupdating1.gif tusing1.gif
	${INSTALL_DATA} ${WRKSRC}/Docs/PunkBuster/players/${players} \
		${BASEDOCDIR}/Docs/PunkBuster/players
.endfor
.for pbhtm in la001293.htm lc000993.htm ls000993.htm ma001293.htm mc000993.htm \
	ms000993.htm wa001293.htm wc000993.htm ws000993.htm
	${INSTALL_DATA} ${WRKSRC}/pb/htm/${pbhtm} ${BASEDOCDIR}/pb/htm
.endfor
	${INSTALL_DATA} ${WRKSRC}/pb/PB_EULA.txt ${BASEDOCDIR}/pb

.include "../../mk/bsd.pkg.mk"
