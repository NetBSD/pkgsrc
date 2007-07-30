# $NetBSD: Makefile,v 1.12 2007/07/30 22:01:11 jlam Exp $

DISTNAME=	suse_base-${SUSE_VERSION}
PKGREVISION=	5
CATEGORIES=	emulators

MAINTAINER=	tonio@NetBSD.org
COMMENT=	Linux compatibility package

CONFLICTS=	linux_SuSE-5.3 linux_lib-2.4 linuxppc_lib-[0-9]*

# These files are managed by the +INSTALL/+DEINSTALL scripts.
CHECK_FILES_SKIP+=	${EMULDIR}/dev/.*
CHECK_FILES_SKIP+=	${EMULDIR}/etc/ld.so.cache
CHECK_FILES_SKIP+=	${EMULDIR}/usr/@LINUX_LIBSUBDIR@/libz.so.1

RPMIGNOREPATH=		./etc/bash.bashrc ./etc/bash_completion.d \
			./etc/cron.daily ./etc/csh.cshrc ./etc/csh.login \
			./etc/inittab ./etc/hushlogins ./etc/java \
			./etc/mailcap ./etc/mime.types ./etc/nsswitch.conf \
			./etc/pam.d ./etc/profile ./etc/profile.dos \
			./etc/rc.d.README ./etc/rpc ./etc/shells ./etc/ttytype

LINUX_LDD=		${EMULDIR}/usr/bin/ldd
LINUX_LDCONFIG=		${EMULDIR}/usr/sbin/ldconfig

INSTALLATION_DIRS=	sbin
OWN_DIRS+=		${EMULSUBDIR}

SUBST_CLASSES+=		suse
SUBST_STAGE.suse=	do-build
SUBST_FILES.suse=	SuSE-release linux-mkpwd.sh
SUBST_VARS.suse=	EMULDIR LINUX_BASE SUSE_ARCH SUSE_VERSION

# Some platforms, e.g. FreeBSD, need to "brand" the ELF binaries to
# the correct type.
#
BRANDELF_CMD=	${BRANDELF:D${BRANDELF} -t Linux ${LINUX_LDCONFIG}:U${TRUE}}

post-extract:
	${CP} ${FILESDIR}/SuSE-release ${WRKSRC}
	${CP} ${FILESDIR}/*.sh ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/linux-mkpwd.sh \
		${PREFIX}/sbin/${LINUX_BASE}-mkpwd
	${INSTALL_DATA} ${WRKSRC}/SuSE-release ${EMULDIR}/etc
	${BRANDELF_CMD}
	${SED}	-e 's:#! :#! ${EMULDIR}:' \
		-e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' \
		${LINUX_LDD} > ${LINUX_LDD}.new
	${MV} ${LINUX_LDD}.new ${LINUX_LDD}
	${CHMOD} +x ${LINUX_LDD}

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
