# $NetBSD: Makefile,v 1.1.1.1 2003/02/16 19:54:56 bad Exp $

DISTNAME=	VMware-workstation-3.2.0-2230
PKGNAME=	vmware-3.2.0
WRKSRC=		${WRKDIR}/vmware-distrib
CATEGORIES=	emulators
MASTER_SITES=   http://www4.vmware.com/software/ \
		http://www.vmware.com/download1/software/ \
		ftp://download1.vmware.com/pub/software/ \
		http://vmware-svca.www.conxion.com/software/ \
		http://vmware-chil.www.conxion.com/software/ \
		http://vmware-heva.www.conxion.com/software/ \
		ftp://vmware.wespe.de/pub/software/ \
		ftp://mirror.aarnet.edu.au/pub/vmware/software/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.vmware.com/
COMMENT=	VMware emulator 3.x

CONFLICTS=	vmware-2.*

DEPENDS+=	vmware-module-3.*:../../emulators/vmware-module3
DEPENDS+=	suse_vmware>=6.4nb1:../../emulators/${SUSE_DIR_PREFIX}_vmware

LICENSE=	vmware-license

CHECK_SHLIBS=	NO

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# We could install it into /etc/vmware, but that would mean we install
# it somewhere out of ${PREFIX}, which is not a good idea, and the linux
# emulation has a fallbackmode to look into ${PREFIX}/emul/linux/etc,
# so use this way.
VMWARE_CFG_DIR=		${PREFIX}/emul/linux/etc/vmware

.include "../../mk/bsd.prefs.mk"

do-build:
	${GZCAT} ${WRKSRC}/man/man1/vmware.1.gz > ${WRKDIR}/vmware.1

do-install: do-install-dirs do-install-binaries do-install-docs \
		do-install-share

do-install-dirs:
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware
	for dirs in bin configurator doc isoimages help licenses messages smb xkeymap; do \
		${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/$$dirs; \
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/licenses/site
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/licenses/user
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/messages/chef
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/messages/ja
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/messages/jive
	${INSTALL_DATA_DIR} ${PREFIX}/share/vmware/smb/codepages
	${INSTALL_DATA_DIR} ${VMWARE_CFG_DIR}

do-install-binaries:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${CHMOD} u+s ${PREFIX}/bin/vmware

do-install-docs:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/vmware/doc/

do-install-share:
	${INSTALL_SCRIPT} ${WRKSRC}/lib/bin/* ${PREFIX}/share/vmware/bin/
	${INSTALL_DATA} ${WRKSRC}/lib/help/* ${PREFIX}/share/vmware/help/
	${INSTALL_DATA} ${WRKSRC}/lib/xkeymap/* ${PREFIX}/share/vmware/xkeymap/
	${INSTALL_DATA} ${WRKSRC}/lib/isoimages/* ${PREFIX}/share/vmware/isoimages/
	${INSTALL_DATA} ${WRKSRC}/lib/licenses/user/* ${PREFIX}/share/vmware/licenses/user/
	${INSTALL_DATA} ${WRKSRC}/lib/messages/chef/* ${PREFIX}/share/vmware/messages/chef/
	${INSTALL_DATA} ${WRKSRC}/lib/messages/ja/* ${PREFIX}/share/vmware/messages/ja/
	${INSTALL_DATA} ${WRKSRC}/lib/messages/jive/* ${PREFIX}/share/vmware/messages/jive/
	${INSTALL_DATA} ${WRKSRC}/lib/smb/codepages/* ${PREFIX}/share/vmware/smb/codepages/
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/* ${PREFIX}/share/vmware/configurator/
	${INSTALL_DATA} ${WRKSRC}/lib/config ${PREFIX}/share/vmware/
	${INSTALL_MAN} ${WRKDIR}/vmware.1 ${PREFIX}/man/man1/

post-install:
	@${RM} -f ${VMWARE_CFG_DIR}/config
	@(								\
	${ECHO} "vmware.fullpath = \"${PREFIX}/bin/vmware\"";		\
	${ECHO} "wizard.fullpath = \"${PREFIX}/bin/vmware-wizard\"";	\
	${ECHO} "dhcpd.fullpath = \"${PREFIX}/bin/vmware-dhcpd\"";	\
	${ECHO} "natd.fullpath = \"${PREFIX}/bin/vmware-natd\"";	\
	${ECHO} "smbpasswd.fullpath = \"${PREFIX}/bin/vmware-smbpasswd\"";	\
	${ECHO} "libdir = \"${PREFIX}/share/vmware\"";			\
	${ECHO} "vmnet1.HostOnlyAddress = \"172.16.212.1\"";		\
	${ECHO} "vmnet1.HostOnlyNetMask = \"255.255.255.0\"";		\
	${ECHO} "host.FSSupportLocking1 = 0x1";		\
	) > ${VMWARE_CFG_DIR}/config

.include "../suse_linux/Makefile.application"
