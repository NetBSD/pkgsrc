# $NetBSD: Makefile,v 1.10 2005/06/16 06:57:51 jlam Exp $

DISTNAME=	VMware-2.0.4-1142
PKGNAME=	vmware-2.0.4
CATEGORIES=	emulators
MASTER_SITES=   http://www4.vmware.com/software/ \
		http://www.vmware.com/download1/software/ \
		ftp://download1.vmware.com/pub/software/ \
		http://vmware-svca.www.conxion.com/software/ \
		http://vmware-chil.www.conxion.com/software/ \
		http://vmware-heva.www.conxion.com/software/ \
		ftp://vmware.wespe.de/pub/software/ \
		ftp://mirror.aarnet.edu.au/pub/vmware/software/

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://www.vmware.com/
COMMENT=	VMware 2.x emulator

CONFLICTS=	vmware-3*

DEPENDS+=	vmware-module-1.*:../../emulators/vmware-module
DEPENDS+=	suse_vmware>=6.4nb1:../../emulators/${SUSE_DIR_PREFIX}_vmware

LICENSE=	vmware-license

WRKSRC=		${WRKDIR}/vmware-distrib
CHECK_SHLIBS=	NO

ONLY_FOR_PLATFORM=	NetBSD-*-i386

# We could install it into /etc/vmware, but that would mean we install
# it somewhere out of ${PREFIX}, which is not a good idea, and the linux
# emulation has a fallbackmode to look into ${PREFIX}/emul/linux/etc,
# so use this way.
VMWARE_CFG_DIR=		${PREFIX}/emul/linux/etc/vmware

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin man/man1

do-build:
	${GZCAT} ${WRKSRC}/man/man1/vmware.1.gz > ${WRKDIR}/vmware.1

do-install: do-install-dirs do-install-binaries do-install-docs \
		do-install-share

do-install-dirs:
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware
	for dirs in configurator doc floppies help smb xkeymap; do \
		${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/$$dirs; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/smb/codepages
	${INSTALL_DATA_DIR} ${VMWARE_CFG_DIR}

do-install-binaries:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin
	${CHMOD} u+s ${PREFIX}/bin/vmware

do-install-docs:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/vmware/doc

do-install-share:
	${INSTALL_DATA} ${WRKSRC}/lib/help/* ${PREFIX}/share/vmware/help
	${INSTALL_DATA} ${WRKSRC}/lib/xkeymap/* ${PREFIX}/share/vmware/xkeymap
	${INSTALL_DATA} ${WRKSRC}/lib/floppies/* ${PREFIX}/share/vmware/floppies
	${INSTALL_DATA} ${WRKSRC}/lib/smb/codepages/* ${PREFIX}/share/vmware/smb/codepages
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/* ${PREFIX}/share/vmware/configurator
	${INSTALL_DATA} ${WRKSRC}/lib/config ${PREFIX}/share/vmware
	${INSTALL_DATA} ${WRKSRC}/lib/floppy.nvr ${PREFIX}/share/vmware
	${INSTALL_MAN} ${WRKDIR}/vmware.1 ${PREFIX}/man/man1

post-install:
	@${RM} -f ${VMWARE_CFG_DIR}/config
	@(								\
	${ECHO} "vmware.fullpath = \"${PREFIX}/bin/vmware\"";		\
	${ECHO} "wizard.fullpath = \"${PREFIX}/bin/vmware-wizard\"";	\
	${ECHO} "dhcpd.fullpath = \"${PREFIX}/bin/vmware-dhcpd\"";	\
	${ECHO} "loop.fullpath = \"${PREFIX}/bin/vmware-loop\"";	\
	${ECHO} "smbpasswd.fullpath = \"${PREFIX}/bin/vmware-smbpasswd\"";	\
	${ECHO} "libdir = \"${PREFIX}/share/vmware\"";			\
	${ECHO} "vmnet1.HostOnlyAddress = \"172.16.212.1\"";		\
	${ECHO} "vmnet1.HostOnlyNetMask = \"255.255.255.0\"";		\
	) > ${VMWARE_CFG_DIR}/config

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
