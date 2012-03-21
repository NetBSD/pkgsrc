# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:35:50 obache Exp $

DISTNAME=	suse_base-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	aaa_base-${SUSE_VERSION}-534.107.1.${SUSE_ARCH}
RPMPKGS+=	bash-4.2-1.8.1.${SUSE_ARCH}
RPMPKGS+=	coreutils-8.14-3.1.2.${SUSE_ARCH}
RPMPKGS+=	cyrus-sasl-2.1.23-20.1.2.${SUSE_ARCH}
RPMPKGS+=	findutils-4.4.2-17.1.2.${SUSE_ARCH}
RPMPKGS+=	gdbm-1.8.3-388.1.3.${SUSE_ARCH}
RPMUPDPKGS+=	glibc-2.14.1-14.25.1.${SUSE_ARCH}
RPMPKGS+=	keyutils-1.5.3-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libFLAC8-1.2.1-88.1.2.${SUSE_ARCH}
RPMPKGS+=	libacl1-2.2.51-4.1.4.${SUSE_ARCH}
RPMPKGS+=	libattr1-2.4.46-5.1.5.${SUSE_ARCH}
RPMPKGS+=	libcap2-2.22-2.1.4.${SUSE_ARCH}
RPMPKGS+=	libgcc46-4.6.2_20111026-1.1.4.${SUSE_ARCH}
RPMPKGS+=	libidn-1.22-7.1.2.${SUSE_ARCH}
RPMPKGS+=	libldap-2_4-2-2.4.26-3.1.2.${SUSE_ARCH}
RPMPKGS+=	libncurses5-5.8-5.1.4.${SUSE_ARCH}
RPMPKGS+=	libncurses6-5.8-5.1.4.${SUSE_ARCH}
RPMPKGS+=	libogg0-1.2.2-8.1.2.${SUSE_ARCH}
RPMPKGS+=	libpcre0-8.13-2.1.2.${SUSE_ARCH}
RPMPKGS+=	libreadline6-6.2-1.8.1.${SUSE_ARCH}
RPMPKGS+=	libselinux1-2.0.91-14.1.12.${SUSE_ARCH}
RPMPKGS+=	libsndfile-1.0.25-6.1.2.${SUSE_ARCH}
RPMPKGS+=	libssh2-1-1.2.9-7.1.3.${SUSE_ARCH}
RPMPKGS+=	libstdc++46-4.6.2_20111026-1.1.4.${SUSE_ARCH}
RPMUPDPKGS+=	libuuid1-2.20.1-1.8.1.${SUSE_ARCH}
RPMUPDPKGS+=	libvorbis0-1.3.2-12.3.1.${SUSE_ARCH}
RPMPKGS+=	mozilla-nspr-4.8.9-3.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	mozilla-nss-3.13.1-9.11.1.${SUSE_ARCH}
RPMPKGS+=	net-tools-1.60-751.1.2.${SUSE_ARCH}
RPMPKGS+=	tcpd-7.6-870.1.2.${SUSE_ARCH}
RPMUPDPKGS+=	zlib-1.2.5_git201105272030-20.3.1.${SUSE_ARCH}

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
	${CP} ${FILESDIR}/SuSE-release ${WRKSRC}
	${CP} ${FILESDIR}/*.sh ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/linux-mkpwd.sh \
		${DESTDIR}${PREFIX}/sbin/${LINUX_BASE}-mkpwd
	${INSTALL_DATA} ${WRKSRC}/SuSE-release ${DESTDIR}${EMULDIR}/etc
	${BRANDELF_CMD}
	${SED}	-e 's:#! :#! ${EMULDIR}:' \
		-e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' \
		${DESTDIR}${LINUX_LDD} > ${DESTDIR}${LINUX_LDD}.new
	${MV} ${DESTDIR}${LINUX_LDD}.new ${DESTDIR}${LINUX_LDD}
	${CHMOD} +x ${DESTDIR}${LINUX_LDD}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
