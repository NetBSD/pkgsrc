# $NetBSD: Makefile,v 1.35 2009/05/19 08:59:15 wiz Exp $

DISTNAME=	linuxq3apoint-1.32b.x86
PKGREVISION=	3
PKGNAME=	quake3arena-1.32b
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/quake3/linux/ \
		ftp://mirrors.xmission.com/idsoftware/quake3/linux/
EXTRACT_SUFX=	.run

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.quake3arena.com/
COMMENT=	Quake 3 Arena -- first person shooter (binary only, no data files)
LICENSE=	quake3arena-license

RESTRICTED=	Terms are too complicated to evaluate.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

CONFLICTS=	quake3arena-demo-[0-9]*

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base x11 glx

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gtar gunzip pax tail

# The distfile is a self-extracting shell script.  "266" is a magic
# number that's taken from the distfile itself.
#
EXTRACT_CMD=	tail +266 ${DOWNLOADED_DISTFILE} | gunzip | gtar -xf -

DISTBINNAME=	quake3.x86
BINNAME=	quake3arena

WRKSRC=		${WRKDIR}
LIBDIR=		${PREFIX}/lib/lokigames/${BINNAME}
SHAREDIR=	${PREFIX}/share/doc/lokigames

INSTALLATION_DIRS=	bin

do-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	       -e 's#@@LIBDIR@@#${LIBDIR}#g' \
	       -e 's#@@BINNAME@@#${BINNAME}#g' \
	    <${FILESDIR}/wrapper.sh >${WRKDIR}/${BINNAME}.sh

# The executable must be in the same directory as the data.
do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${LIBDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${BINNAME}.sh ${DESTDIR}${PREFIX}/bin/${BINNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/${DISTBINNAME} \
		${DESTDIR}${LIBDIR}/${BINNAME}
	${INSTALL_DATA} ${WRKSRC}/README-linux.txt ${DESTDIR}${SHAREDIR}/${BINNAME}-README

	cd ${WRKSRC} && pax -rw baseq3 ${DESTDIR}${LIBDIR}

# Some platforms, e.g. FreeBSD, need to "brand" the ELF binaries to
# the correct type.
#
post-install:
	${BRANDELF:D${BRANDELF} -t Linux ${DESTDIR}${PREFIX}/bin/${BINNAME}:U${TRUE}}

.include "../../mk/bsd.pkg.mk"
