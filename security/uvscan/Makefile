# $NetBSD: Makefile,v 1.40 2006/10/14 08:22:31 wiz Exp $

DISTNAME=		vlnx440e
PKGNAME=		uvscan-4.40
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://download.nai.com/products/evaluation/virusscan/english/cmdline/linux/v4.40/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mcafee.com/us/enterprise/products/anti_virus/file_servers_desktops/virusscan_command_line_scanner_windows_unix.html
COMMENT=		Evaluation version of a DOS/Windows file virus scanner

CONFLICTS=		uvscan-dat-[0-9]*

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
.endif

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
NO_CONFIGURE=		yes
LICENSE=		uvscan-license
RESTRICTED=		restrictive 30 day evaluation license
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

DOCDIR=			${PREFIX}/share/doc/uvscan
EGDATDIR=		${PREFIX}/share/examples/uvscan
UVSCANDIR=		${PREFIX}/libexec/uvscan
DATFILES=		clean.dat internet.dat names.dat scan.dat pkgdesc.ini

FILES_SUBST+=		UVSCANDIR=${UVSCANDIR:Q}
FILES_SUBST+=		DATFILES=${DATFILES:Q}

CONF_FILES=		${EGDATDIR}/clean.dat ${UVSCANDIR}/clean.dat
CONF_FILES+=		${EGDATDIR}/names.dat ${UVSCANDIR}/names.dat
CONF_FILES+=		${EGDATDIR}/scan.dat ${UVSCANDIR}/scan.dat
REQD_DIRS=		${UVSCANDIR}

INSTALLATION_DIRS=	bin man/man1 sbin

USE_TOOLS+=		gtar:run

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/update_dat
SUBST_SED.paths+=	-e 's,@UVSCANDIR@,${UVSCANDIR},g'
SUBST_SED.paths+=	-e 's,@DATFILES@,${DATFILES},g'
SUBST_SED.paths+=	-e 's,@AWK@,${AWK},g' -e 's,@CP@,${CP},g'
SUBST_SED.paths+=	-e 's,@BASENAME@,${BASENAME},g'
SUBST_SED.paths+=	-e 's,@ECHO@,${ECHO},g' -e 's,@GREP@,${GREP},g'
SUBST_SED.paths+=	-e 's,@GTAR@,${GTAR},g' -e 's,@MKDIR@,${MKDIR},g'
SUBST_SED.paths+=	-e 's,@MV@,${MV},g' -e 's,@RM@,${RM},g'
SUBST_SED.paths+=	-e 's,@SED@,${SED},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/update_dat.sh ${WRKDIR}/update_dat

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/update_dat ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/uvscan.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${UVSCANDIR}
	${RM} -f ${PREFIX}/bin/uvscan
	${LN} -sf ../${UVSCANDIR:S/${PREFIX}\///}/uvscan ${PREFIX}/bin/uvscan
	${INSTALL_DATA} ${WRKSRC}/liblnxfv.so.4 ${UVSCANDIR}
	${RM} -f ${UVSCANDIR}/liblnxfv.so
	${LN} -s liblnxfv.so.4 ${UVSCANDIR}/liblnxfv.so
	${INSTALL_DATA_DIR} ${PREFIX}/emul/linux/usr/local/lib
	for file in liblnxfv.so.4 liblnxfv.so; do			\
		${RM} -f ${PREFIX}/emul/linux/usr/local/lib/$${file};	\
		${LN} -s ${UVSCANDIR}/$${file}				\
			${PREFIX}/emul/linux/usr/local/lib;		\
	done
	for file in license.dat messages.dat; do			\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${UVSCANDIR};	\
	done
	${INSTALL_DATA_DIR} ${EGDATDIR}
	for file in ${DATFILES}; do					\
		if [ -f ${WRKSRC}/$${file} ]; then			\
			${INSTALL_DATA} ${WRKSRC}/$${file} ${EGDATDIR};	\
		fi;							\
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in contact.txt e4400upg.pdf license.txt ; do		\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
