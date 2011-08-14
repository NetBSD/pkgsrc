# $NetBSD: Makefile,v 1.8 2011/08/14 14:11:05 chs Exp $

DISTNAME=	suse_base-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators
DISTFILES+=	aaa_base-11.3-8.9.1.${SUSE_ARCH}.rpm
DISTFILES+=	bash-4.1-8.1.${SUSE_ARCH}.rpm
DISTFILES+=	coreutils-7.1-10.1.${SUSE_ARCH}.rpm
DISTFILES+=	cyrus-sasl-2.1.23-11.1.${SUSE_ARCH}.rpm
DISTFILES+=	findutils-4.4.2-4.1.${SUSE_ARCH}.rpm
DISTFILES+=	gdbm-1.8.3-373.4.${SUSE_ARCH}.rpm
DISTFILES+=	glibc-2.11.2-3.3.1.${SUSE_ARCH}.rpm
DISTFILES+=	keyutils-libs-1.3-1.9.${SUSE_ARCH}.rpm
DISTFILES+=	libFLAC8-1.2.1-75.1.${SUSE_ARCH}.rpm
DISTFILES+=	libacl-2.2.48-8.1.${SUSE_ARCH}.rpm
DISTFILES+=	libattr-2.4.44-7.1.${SUSE_ARCH}.rpm
DISTFILES+=	libcap2-2.16-9.1.${SUSE_ARCH}.rpm
DISTFILES+=	libgcc45-4.5.0_20100604-1.12.${SUSE_ARCH}.rpm
DISTFILES+=	libidn-1.15-4.1.${SUSE_ARCH}.rpm
DISTFILES+=	libldap-2_4-2-2.4.21-9.1.${SUSE_ARCH}.rpm
DISTFILES+=	libncurses5-5.7-3.39.${SUSE_ARCH}.rpm
DISTFILES+=	libncurses6-5.7-3.39.${SUSE_ARCH}.rpm
DISTFILES+=	libogg0-1.1.4-7.1.${SUSE_ARCH}.rpm
DISTFILES+=	libpcre0-7.9.0-6.7.${SUSE_ARCH}.rpm
DISTFILES+=	libreadline6-6.1-8.1.${SUSE_ARCH}.rpm
DISTFILES+=	libselinux1-2.0.91-4.2.${SUSE_ARCH}.rpm
DISTFILES+=	libsndfile-1.0.20-8.3.1.${SUSE_ARCH}.rpm
DISTFILES+=	libssh2-1-1.2.2_git200911281702-3.1.${SUSE_ARCH}.rpm
DISTFILES+=	libstdc++45-4.5.0_20100604-1.12.${SUSE_ARCH}.rpm
DISTFILES+=	libuuid1-2.17.2-5.3.${SUSE_ARCH}.rpm
DISTFILES+=	libvorbis-1.2.3-5.1.${SUSE_ARCH}.rpm
DISTFILES+=	mozilla-nspr-4.8.4-4.1.${SUSE_ARCH}.rpm
DISTFILES+=	mozilla-nss-3.12.6-6.1.${SUSE_ARCH}.rpm
DISTFILES+=	net-tools-1.60-741.1.${SUSE_ARCH}.rpm
DISTFILES+=	tcpd-7.6-863.1.${SUSE_ARCH}.rpm
DISTFILES+=	zlib-1.2.3-141.1.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
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

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
