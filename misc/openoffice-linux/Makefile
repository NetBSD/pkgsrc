# $NetBSD: Makefile,v 1.25 2004/10/01 10:37:33 grant Exp $

DISTNAME=		OOo_1.1.2_LinuxIntel_install
PKGNAME=		openoffice-linux-1.1.2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_OPENOFFICE:=stable/1.1.2/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		openoffice-linux-112-services.rdb.bz2
SITES_openoffice-linux-112-services.rdb.bz2=http://www.fs.tum.de/~mrauch/OpenOffice/download/\
			ftp://ftp.NetBSD.org/pub/NetBSD/misc/mrauch/

MAINTAINER=		mrauch@NetBSD.org
HOMEPAGE=		http://www.openoffice.org/
COMMENT=		Integrated office productivity suite (binary pkg)

NO_CONFIGURE=           yes

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	Linux-*-i[3-6]86

TEMP?=			${WRKSRC}
CHECK_SHLIBS=		no

.include "../../mk/bsd.prefs.mk"

do-build:

.if ${OPSYS} == "NetBSD"
USE_PKGINSTALL=         yes
SUPPORT_FILES=          /dev/null /emul/linux/etc/mtab
.endif

pre-install:
	${CP} ${WRKSRC}/setup.ins ${WRKSRC}/setup.ins.orig
	${SED}  -e "s|/usr/bin/soffice|${PREFIX}/bin/soffice.orig|g"	\
		-e "s|not(existsFile(searchdir, searchfile))|true|g"	\
		<${WRKSRC}/setup.ins.orig >${WRKSRC}/setup.ins
.     if ${OPSYS}=="NetBSD" && !exists(/emul/linux/etc/mtab)
	${CP} /dev/null /emul/linux/etc/mtab
.     endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/OpenOffice.org1.1.2/program
	${INSTALL_DATA} ${WRKDIR}/openoffice-linux-112-services.rdb	\
		${PREFIX}/OpenOffice.org1.1.2/program/services.rdb
	${SH} -c "cd ${WRKSRC}; ./install --prefix=${PREFIX}"
	${RM} -f ${PREFIX}/bin/soffice.orig
	${SED}	-e "s|@@PREFIX@@|${PREFIX}|g"				\
		< ${FILESDIR}/soffice > ${PREFIX}/bin/soffice
	${CHMOD} +x ${PREFIX}/bin/soffice
.for i in scalc sdraw simpress swriter
	${LN} -sf ${PREFIX}/OpenOffice.org1.1.2/program/$i ${PREFIX}/bin/$i
.endfor

# everything specific to your OS/Arch goes into its own Makefile
# group together i386, i486, i586 and i686 (for Linux)
#
ARCH=	${MACHINE_ARCH:C/i[3-6]86/i386/g}

.if exists(Makefile.${OPSYS}.${ARCH})
.  include "Makefile.${OPSYS}.${ARCH}"
.endif

.include "../../mk/bsd.pkg.mk"
