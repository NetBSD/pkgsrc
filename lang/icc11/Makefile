# $NetBSD: Makefile,v 1.3 2012/10/02 20:11:42 asau Exp $

ICC_MAJOR_VERSION=	11.1
ICC_MINOR_VERSION=	080
ICC_VERSION=		${ICC_MAJOR_VERSION}.${ICC_MINOR_VERSION}
CATEGORIES=		lang
DISTNAME=		l_cproc_p_${ICC_VERSION}
PKGNAME=		icc11-${ICC_VERSION}
EXTRACT_SUFX=		.tgz
EXTRACT_ELEMENTS=	${ICC_EXTRACT_RPMS}
MASTER_SITES=# empty

MAINTAINER=		alnsn@NetBSD.org
HOMEPAGE_COMMERCIAL=	http://software.intel.com/en-us/articles/intel-compilers/
HOMEPAGE_NONCOMMERCIAL=	http://software.intel.com/en-us/articles/non-commercial-software-development/
HOMEPAGE=		${HOMEPAGE_NONCOMMERCIAL}
COMMENT=		Intel C++ Compiler for Linux
LICENSE=		intel-icc11-license

RESTRICTED=		Intel forbids any redistribution
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

ICC_PREFIX=		${PREFIX}/icc11

ONLY_FOR_PLATFORM+=	NetBSD-*-i386 NetBSD-*-x86_64 \
			Linux-*-i386 Linux-*-x86_64

USE_TOOLS+=		pax make rpm2pkg

USE_LANGUAGES+=	c

BUILD_DEPENDS+=		rpm2pkg>=2.1:../../pkgtools/rpm2pkg

DEPENDS+=		gcc34>=3.4.6:../../lang/gcc34
DEPENDS+=		binutils>=2.17:../../devel/binutils

GCC_PREFIX=		${BUILDLINK_PREFIX.gcc34}
BINUTILS_PREFIX=	${PREFIX}/${MACHINE_GNU_PLATFORM}

EMUL_PLATFORMS=		linux-i386 linux-x86_64
EMUL_MODULES.linux=	base compat
EMUL_REQD=		suse>=11.3

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
ICC_ARCH=		ia32
.else
ICC_ARCH=		intel64
.endif

SUBST_CLASSES+=		installdir vars

SUBST_MESSAGE.installdir=Substituting <INSTALLDIR>
SUBST_STAGE.installdir=	pre-configure
SUBST_SED.installdir=	-e 's,<INSTALLDIR>,${ICC_PREFIX},g'
SUBST_FILES.installdir=	icc11/bin/iccvars.sh           \
			icc11/bin/iccvars.csh          \
			icc11/bin/ia32/iccvars_ia32.sh \
                       	icc11/bin/ia32/iccvars_ia32.csh

.if ${MACHINE_ARCH} == "x86_64"
SUBST_FILES.installdir+=icc11/bin/intel64/iccvars_intel64.sh \
                       	icc11/bin/intel64/iccvars_intel64.csh
.endif

SUBST_STAGE.vars=	pre-configure
SUBST_VARS.vars=	ICC_PREFIX ICC_ARCH OPSYS_EMULDIR GCC_PREFIX BINUTILS_PREFIX
SUBST_FILES.vars=	util.h icc xiar README.pkgsrc

PLIST_VARS+=		linux netbsd x86_64 linux_x86_64 netbsd_x86_64
PLIST.${LOWER_OPSYS}=	yes
PLIST.${MACHINE_ARCH}=	yes
PLIST.${LOWER_OPSYS}_${MACHINE_ARCH}=yes

ICC_EXTRACT_RPMS=\
	${DISTNAME}/rpm/intel-cproc${ICC_MINOR_VERSION}-11.1-1.i486.rpm       \
	${DISTNAME}/rpm/intel-cproc${ICC_MINOR_VERSION}-11.1-1.x86_64.rpm     \
	${DISTNAME}/rpm/intel-cprocsdk${ICC_MINOR_VERSION}-11.1-1.noarch.rpm  \
	${DISTNAME}/rpm/intel-cprolib${ICC_MINOR_VERSION}-11.1-1.i486.rpm     \
	${DISTNAME}/rpm/intel-cprolibdev${ICC_MINOR_VERSION}-11.1-1.i486.rpm

.if ${MACHINE_ARCH} == "x86_64"
ICC_EXTRACT_RPMS+=\
	${DISTNAME}/rpm/intel-cprolib${ICC_MINOR_VERSION}-11.1-1.x86_64.rpm \
	${DISTNAME}/rpm/intel-cprolibdev${ICC_MINOR_VERSION}-11.1-1.x86_64.rpm
.endif

WRKSRC=			${WRKDIR}/${ICC_MAJOR_VERSION}

post-extract:
	cd ${WRKDIR} && rpm2pkg -s 4 ${ICC_EXTRACT_RPMS}
	cd ${WRKSRC} && mv ${ICC_MINOR_VERSION} icc11
	cd ${FILESDIR} && find . ! -type d | pax -rw ${WRKSRC}
	if [ -d ${FILESDIR}/${LOWER_OPSYS} ]; then \
	    cd ${FILESDIR}/${LOWER_OPSYS} && \
	    find . ! -type d | pax -rw ${WRKSRC}; fi

do-build:
	cd ${WRKSRC} && make ${LOWER_OPSYS}-${ICC_ARCH}

do-install:
	cd ${WRKSRC} && make install-${LOWER_OPSYS}-${ICC_ARCH} \
		PREFIX=${DESTDIR}${PREFIX} PKGMANDIR=${PKGMANDIR}

.include "../../lang/gcc34/buildlink3.mk"
.include "../../devel/binutils/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
