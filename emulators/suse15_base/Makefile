# $NetBSD: Makefile,v 1.2 2022/11/04 17:37:20 hauke Exp $

PKGNAME=	suse_base-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	aaa_base-84.87+git20180409.04c9dae-3.57.1.${SUSE_ARCH}
RPMPKGS+=	bash-4.4-150400.25.22.${SUSE_ARCH}
RPMPKGS+=	coreutils-8.32-150400.7.5.${SUSE_ARCH}
RPMPKGS+=	findutils-4.8.0-1.20.${SUSE_ARCH}
RPMPKGS+=	glibc-2.31-150300.37.1.${SUSE_ARCH}
RPMPKGS+=	keyutils-1.6.3-5.6.1.${SUSE_ARCH}
RPMPKGS+=	libacl1-2.2.52-4.3.1.${SUSE_ARCH}
RPMPKGS+=	libattr1-2.4.47-2.19.${SUSE_ARCH}
RPMPKGS+=	libcap2-2.63-150400.1.7.${SUSE_ARCH}
RPMPKGS+=	libcrypt1-4.4.15-150300.4.4.3.${SUSE_ARCH}
RPMPKGS+=	libgcc_s1-11.3.0+git1637-150000.1.11.2.${SUSE_ARCH}
RPMPKGS+=	libgdbm4-1.12-1.418.${SUSE_ARCH}
RPMPKGS+=	libgmp10-6.1.2-4.9.1.${SUSE_ARCH}
RPMPKGS+=	libkeyutils1-1.6.3-5.6.1.${SUSE_ARCH}
RPMPKGS+=	liblzma5-5.2.3-150000.4.7.1.${SUSE_ARCH}
RPMPKGS+=	libncurses5-6.1-150000.5.12.1.${SUSE_ARCH}
RPMPKGS+=	libncurses6-6.1-150000.5.12.1.${SUSE_ARCH}
RPMPKGS+=	libpcre1-8.45-150000.20.13.1.${SUSE_ARCH}
RPMPKGS+=	libreadline6-6.3-bp155.2.6.${SUSE_ARCH}
RPMPKGS+=	libreadline7-7.0-150400.25.22.${SUSE_ARCH}
RPMPKGS+=	libselinux1-3.1-150400.1.69.${SUSE_ARCH}
RPMPKGS+=	libstdc++6-11.3.0+git1637-150000.1.11.2.${SUSE_ARCH}
RPMPKGS+=	libuuid1-2.37.2-150400.8.3.1.${SUSE_ARCH}
RPMPKGS+=	libz1-1.2.11-150000.3.33.1.${SUSE_ARCH}
RPMPKGS+=	net-tools-2.0+git20170221.479bb4a-3.11.${SUSE_ARCH}
RPMPKGS+=	openSUSE-release-${SUSE_VERSION}-lp155.180.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package

# These files are managed by the +INSTALL/+DEINSTALL scripts.
CHECK_FILES_SKIP+=	${EMULDIR}/dev/.*
CHECK_FILES_SKIP+=	${EMULDIR}/etc/ld.so.cache

RPMIGNOREPATH=		./etc/bash.bashrc ./etc/bash_completion.d \
			./etc/cron.daily ./etc/csh.cshrc ./etc/csh.login \
			./etc/inittab ./etc/hushlogins ./etc/java \
			./etc/mailcap ./etc/mime.types ./etc/nsswitch.conf \
			./etc/pam.d ./etc/profile ./etc/profile.dos \
			./etc/rc.d.README ./etc/rpc ./etc/shells ./etc/ttytype

LINUX_LDD=		${EMULDIR}/usr/bin/ldd
LINUX_LDCONFIG=		${EMULDIR}/sbin/ldconfig

INSTALLATION_DIRS+=	${EMULDIR}/etc ${EMULDIR}/dev/shm ${EMULDIR}/var/lock
INSTALLATION_DIRS+=	sbin
OWN_DIRS+=		${EMULSUBDIR}

SUBST_CLASSES+=		suse
SUBST_STAGE.suse=	do-build
SUBST_FILES.suse=	linux-mkpwd.sh
SUBST_VARS.suse=	EMULDIR LINUX_BASE SUSE_ARCH SUSE_VERSION

# Some platforms, e.g. FreeBSD, need to "brand" the ELF binaries to
# the correct type.
#
BRANDELF_CMD=	${BRANDELF:D${BRANDELF} -t Linux ${DESTDIR}${LINUX_LDCONFIG}:U${TRUE}}

# This package provides the ldconfig(8) binary, so that binary can't
# be used during postremove.
#
LDCONFIG_REMOVE_CMD=	${TRUE}

post-extract:
	${CP} ${FILESDIR}/*.sh ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/linux-mkpwd.sh \
		${DESTDIR}${PREFIX}/sbin/${LINUX_BASE}-mkpwd
	${BRANDELF_CMD}
	${SED}	-e 's:#! :#! ${EMULDIR}:' \
		-e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' \
		${DESTDIR}${LINUX_LDD} > ${DESTDIR}${LINUX_LDD}.new
	${MV} ${DESTDIR}${LINUX_LDD}.new ${DESTDIR}${LINUX_LDD}
	${CHMOD} +x ${DESTDIR}${LINUX_LDD}

.include "../../emulators/suse15_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
