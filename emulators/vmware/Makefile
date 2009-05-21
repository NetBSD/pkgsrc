# $NetBSD: Makefile,v 1.22 2009/05/21 10:44:57 zafer Exp $

DISTNAME=	VMware-2.0.4-1142
PKGNAME=	vmware-2.0.4
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_BACKUP}	

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vmware.com/
COMMENT=	VMware 2.x emulator
LICENSE=	vmware-license

DEPENDS+=	vmware-module-1.*:../../emulators/vmware-module

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	vmware

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=			${WRKDIR}/vmware-distrib

# We could install it into /etc/vmware, but that would mean we install
# it somewhere out of ${PREFIX}, which is not a good idea, and the linux
# emulation has a fallbackmode to look into ${PREFIX}/emul/linux/etc,
# so use this way.
VMWARE_CFG_DIR=		${PREFIX}/emul/linux/etc/vmware

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	${GZCAT} ${WRKSRC}/man/man1/vmware.1.gz > ${WRKDIR}/vmware.1

do-install: do-install-dirs do-install-binaries do-install-docs \
		do-install-share

do-install-dirs:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware
	for dirs in configurator doc floppies help smb xkeymap; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/$$dirs; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vmware/smb/codepages
	${INSTALL_DATA_DIR} ${DESTDIR}${VMWARE_CFG_DIR}

do-install-binaries:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin
	${CHMOD} u+s ${DESTDIR}${PREFIX}/bin/vmware

do-install-docs:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/vmware/doc

do-install-share:
	${INSTALL_DATA} ${WRKSRC}/lib/help/* ${DESTDIR}${PREFIX}/share/vmware/help
	${INSTALL_DATA} ${WRKSRC}/lib/xkeymap/* ${DESTDIR}${PREFIX}/share/vmware/xkeymap
	${INSTALL_DATA} ${WRKSRC}/lib/floppies/* ${DESTDIR}${PREFIX}/share/vmware/floppies
	${INSTALL_DATA} ${WRKSRC}/lib/smb/codepages/* ${DESTDIR}${PREFIX}/share/vmware/smb/codepages
	${INSTALL_DATA} ${WRKSRC}/lib/configurator/* ${DESTDIR}${PREFIX}/share/vmware/configurator
	${INSTALL_DATA} ${WRKSRC}/lib/config ${DESTDIR}${PREFIX}/share/vmware
	${INSTALL_DATA} ${WRKSRC}/lib/floppy.nvr ${DESTDIR}${PREFIX}/share/vmware
	${INSTALL_MAN} ${WRKDIR}/vmware.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

post-install:
	@${RM} -f ${DESTDIR}${VMWARE_CFG_DIR}/config
	@(								\
	${ECHO} "vmware.fullpath = \"${PREFIX}/bin/vmware\"";		\
	${ECHO} "wizard.fullpath = \"${PREFIX}/bin/vmware-wizard\"";	\
	${ECHO} "dhcpd.fullpath = \"${PREFIX}/bin/vmware-dhcpd\"";	\
	${ECHO} "loop.fullpath = \"${PREFIX}/bin/vmware-loop\"";	\
	${ECHO} "smbpasswd.fullpath = \"${PREFIX}/bin/vmware-smbpasswd\"";	\
	${ECHO} "libdir = \"${PREFIX}/share/vmware\"";			\
	${ECHO} "vmnet1.HostOnlyAddress = \"172.16.212.1\"";		\
	${ECHO} "vmnet1.HostOnlyNetMask = \"255.255.255.0\"";		\
	) > ${DESTDIR}${VMWARE_CFG_DIR}/config

.include "../../mk/bsd.pkg.mk"
