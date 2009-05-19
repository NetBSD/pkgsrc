# $NetBSD: Makefile,v 1.25 2009/05/19 08:59:13 wiz Exp $

DISTNAME=	VMware-workstation-3.2.1-2242
PKGNAME=	vmware-3.2.1pl1
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://download3.vmware.com/software/wkst/

# Binary patch to fix an problem with the nice(3) interface in an
# newer glibc (>= v2.3.3)
VMWARE_BIN_PATCH=	vmware-any-any-update99

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${VMWARE_BIN_PATCH}.tar.gz
SITES.${VMWARE_BIN_PATCH}.tar.gz=	ftp://ftp.cvut.cz/vmware/obsolete/

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.vmware.com/
COMMENT=	VMware emulator 3.x
LICENSE=	vmware-license

DEPENDS+=	vmware-module>=3.2.1.8:../../emulators/vmware-module3

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	vmware
EMUL_REQD=		suse>=6.4nb1

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=			${WRKDIR}/vmware-distrib

# There is a kernel bug in NetBSD 3.0 for vmware.
NOT_FOR_PLATFORM=	NetBSD-3.0*-*

NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# We could install it into /etc/vmware, but that would mean we install
# it somewhere out of ${PREFIX}, which is not a good idea, and the linux
# emulation has a fallbackmode to look into ${PREFIX}/emul/linux/etc,
# so use this way.
VMWARE_CFG_DIR=		${PREFIX}/emul/linux/etc/vmware

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	${GZCAT} ${WRKSRC}/man/man1/vmware.1.gz > ${WRKDIR}/vmware.1
	cd ${WRKDIR}/${VMWARE_BIN_PATCH} &&	\
	${RM} -f update &&			\
	${CC} ${CFLAGS} -o update update.c &&	\
	${CHMOD} u+w ${WRKSRC}/bin/vmware && 	\
	./update vmware ${WRKSRC}/bin/vmware

do-install: do-install-dirs do-install-binaries do-install-docs \
		do-install-share

do-install-dirs:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware
	for dirs in bin configurator doc isoimages help licenses messages smb xkeymap; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/$$dirs; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/licenses/site
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/licenses/user
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/messages/chef
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/messages/ja
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/messages/jive
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/smb/codepages
	${INSTALL_DATA_DIR} ${DESTDIR}${VMWARE_CFG_DIR}

do-install-binaries:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${CHMOD} u+s ${DESTDIR}${PREFIX}/bin/vmware

do-install-docs:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/vmware/doc

do-install-share:
	${INSTALL_SCRIPT} ${WRKSRC}/lib/bin/* ${DESTDIR}${PREFIX}/share/vmware/bin
	${INSTALL_DATA} ${WRKSRC}/lib/help/* ${DESTDIR}${PREFIX}/share/vmware/help
	${INSTALL_DATA} ${WRKSRC}/lib/xkeymap/* ${DESTDIR}${PREFIX}/share/vmware/xkeymap
	${INSTALL_DATA} ${WRKSRC}/lib/isoimages/* ${DESTDIR}${PREFIX}/share/vmware/isoimages
	${INSTALL_DATA} ${WRKSRC}/lib/licenses/user/* ${DESTDIR}${PREFIX}/share/vmware/licenses/user
	${INSTALL_DATA} ${WRKSRC}/lib/messages/chef/* ${DESTDIR}${PREFIX}/share/vmware/messages/chef
	${INSTALL_DATA} ${WRKSRC}/lib/messages/ja/* ${DESTDIR}${PREFIX}/share/vmware/messages/ja
	${INSTALL_DATA} ${WRKSRC}/lib/messages/jive/* ${DESTDIR}${PREFIX}/share/vmware/messages/jive
	${INSTALL_DATA} ${WRKSRC}/lib/smb/codepages/* ${DESTDIR}${PREFIX}/share/vmware/smb/codepages
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/* ${DESTDIR}${PREFIX}/share/vmware/configurator
	${INSTALL_DATA} ${WRKSRC}/lib/config ${DESTDIR}${PREFIX}/share/vmware
	${INSTALL_MAN} ${WRKDIR}/vmware.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

post-install:
	@${RM} -f ${DESTDIR}${VMWARE_CFG_DIR}/config
	@(								\
	${ECHO} "vmware.fullpath = \"${PREFIX}/bin/vmware\"";		\
	${ECHO} "wizard.fullpath = \"${PREFIX}/bin/vmware-wizard\"";	\
	${ECHO} "dhcpd.fullpath = \"${PREFIX}/bin/vmware-dhcpd\"";	\
	${ECHO} "natd.fullpath = \"${PREFIX}/bin/vmware-natd\"";	\
	${ECHO} "smbpasswd.fullpath = \"${PREFIX}/bin/vmware-smbpasswd\"";	\
	${ECHO} "libdir = \"${PREFIX}/share/vmware\"";			\
	${ECHO} "vmnet1.HostOnlyAddress = \"172.16.212.1\"";		\
	${ECHO} "vmnet1.HostOnlyNetMask = \"255.255.255.0\"";		\
	${ECHO} "host.FSSupportLocking1 = 0x1";				\
	${ECHO} "xkeymap.usekeycodeMapIfXFree86 = true";		\
	) > ${DESTDIR}${VMWARE_CFG_DIR}/config

.include "../../mk/bsd.pkg.mk"
