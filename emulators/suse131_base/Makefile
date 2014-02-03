# $NetBSD: Makefile,v 1.2 2014/02/03 03:14:18 obache Exp $

DISTNAME=	suse_base-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMPKGS+=	aaa_base-${SUSE_VERSION}-16.17.1.${SUSE_ARCH}
RPMPKGS+=	bash-4.2-68.1.5.${SUSE_ARCH}
RPMPKGS+=	coreutils-8.21-7.1.3.${SUSE_ARCH}
RPMPKGS+=	findutils-4.5.12-1.1.${SUSE_ARCH}
RPMPKGS+=	libgdbm4-1.10-7.1.2.${SUSE_ARCH}
RPMPKGS+=	glibc-2.18-4.4.1.${SUSE_ARCH}
RPMPKGS+=	keyutils-1.5.5-6.1.3.${SUSE_ARCH}
RPMPKGS+=	libacl1-2.2.52-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libattr1-2.4.47-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libcap2-2.22-10.1.24.${SUSE_ARCH}
RPMPKGS+=	libgcc_s1-4.8.1_20130909-3.2.1.${SUSE_ARCH}
RPMPKGS+=	libgmp10-5.1.2-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libncurses5-5.9-33.1.2.${SUSE_ARCH}
RPMPKGS+=	libpcre1-8.33-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libreadline6-6.2-68.1.5.${SUSE_ARCH}
RPMPKGS+=	libselinux1-2.1.13-4.1.21.${SUSE_ARCH}
RPMPKGS+=	libstdc++6-4.8.1_20130909-3.2.1.${SUSE_ARCH}
RPMPKGS+=	libuuid1-2.23.2-3.1.${SUSE_ARCH}
RPMPKGS+=	net-tools-1.60-763.1.2.${SUSE_ARCH}
RPMPKGS+=	libz1-1.2.8-3.1.2.${SUSE_ARCH}
RPMPKGS+=	liblzma5-5.0.5-2.1.20.${SUSE_ARCH}
RPMPKGS+=	openSUSE-release-${SUSE_VERSION}-1.10.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package

CONFLICTS=	linux_SuSE-5.3 linux_lib-2.4 linuxppc_lib-[0-9]*

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
LINUX_LDCONFIG=		${EMULDIR}/usr/sbin/ldconfig

INSTALLATION_DIRS+=	${EMULDIR}/etc ${EMULDIR}/dev/shm ${EMULDIR}/var/lock
INSTALLATION_DIRS+=	sbin
OWN_DIRS+=		${EMULSUBDIR}

SUBST_CLASSES+=		suse
SUBST_STAGE.suse=	do-build
SUBST_FILES.suse=	SuSE-release linux-mkpwd.sh
SUBST_VARS.suse=	EMULDIR LINUX_BASE SUSE_ARCH SUSE_VERSION

# Some platforms, e.g. FreeBSD, need to "brand" the ELF binaries to
# the correct type.
#
BRANDELF_CMD=	${BRANDELF:D${BRANDELF} -t Linux ${DESTDIR}${LINUX_LDCONFIG}:U${TRUE}}

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

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
