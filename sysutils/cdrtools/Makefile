# $NetBSD: Makefile,v 1.107 2014/05/14 08:41:01 wiz Exp $

DISTNAME=	cdrtools-3.01a24
PKGNAME=	${DISTNAME:S/a/alpha/:S/-pre/pre/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdrtools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://cdrecord.berlios.de/old/private/cdrecord.html
COMMENT=	Software for creating ISO9660 images and writing CD/DVD/Blu-ray
#LICENSE=	CDDL.Schily.txt AND gnu-gpl-v2 AND gnu-lgpl-v2.1

CONFLICTS=	mkisofs-[0-9]* cdrtools-ossdvd-[0-9]* cdrecord-[0-9]* cdrkit-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME:C/a[0-9]*//}

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	gm4 gmake tbl

CFLAGS.NetBSD+=	-DUSE_GETRAWPARTITION
LDFLAGS.NetBSD+=	-lutil

# NetBSD 6.0 (and update releases) have incomplete implemenations of the
# "*at" system calls. Pretend that they aren't present at all to
# avoid build failures.
.if !empty(MACHINE_PLATFORM:MNetBSD-[5-6].*-*) && \
    empty(MACHINE_PLATFORM:MNetBSD-6.99.*-*)
.  for func in faccessat fchmodat fchownat fexecve fstatat linkat mkdirat \
               mkfifoat mknodat openat readlinkat renameat symlinkat unlinkat \
               utimensat
CONFIGURE_ENV+=	ac_cv_func_${func}=no
.  endfor
.endif

# avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=	ARCH=""
MAKE_ENV+=	MAKEPROG="gmake"
MAKE_ENV+=	COPTX=${CFLAGS:Q}
MAKE_ENV+=	LDOPTX=${LDFLAGS:Q}
MAKE_ENV+=	INS_BASE=${PREFIX:Q}
MAKE_FLAGS+=	GMAKE_NOWARN=true
# do we want to compile shared libraries?
# needs changes in the install target and PLIST
#MAKE_ENV+=	LINKMODE=dynamic

# Map PKGSRC_COMPILER to CCOM used by cdrtools build system.
ccmap.gcc=	gcc
MAKE_FLAGS+=	CCOM=${ccmap.${PKGSRC_COMPILER}:Ucc}

# allow us to override the default /etc/default/cdrecord by patching
# the documentation appropriately. Additionally, we also provide a
# MESSAGE stating the reasons we do this, as required by the license.
CDRECORD_CONF?=	${PKG_SYSCONFDIR}/cdrecord.conf

.if ${CDRECORD_CONF} != "/etc/default/cdrecord"
MESSAGE_SRC+=	MESSAGE.cdrecord.conf
MESSAGE_SUBST+=	PKGNAME_NOREV=${PKGNAME_NOREV:Q}
MESSAGE_SUBST+=	CDRECORD_CONF=${CDRECORD_CONF:Q}
.endif

CONF_FILES+=		share/examples/cdrtools/cdrecord ${CDRECORD_CONF}

INSTALLATION_DIRS=	bin lib/siconv ${PKGMANDIR}/man1 ${PKGMANDIR}/man8 \
			share/doc/cdrtools/cdda2wav \
			share/doc/cdrtools/cdrecord \
			share/doc/cdrtools/mkisofs \
			share/examples/cdrtools

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	btcflash/btcflash.1
SUBST_FILES.fix+=	cdrecord/cdrecord.1
SUBST_FILES.fix+=	libcdrdeflt/cdrdeflt.c
SUBST_FILES.fix+=	mkisofs/diag/isoinfo.8
SUBST_FILES.fix+=	readcd/readcd.1
SUBST_SED.fix=		-e "s,/etc/default/cdrecord,${CDRECORD_CONF},g"
SUBST_MESSAGE.fix=	Fixing paths.

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_FILES.oss=	cdda2wav/local.cnf.in
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSSOUND},g"
SUBST_MESSAGE.oss=	Fixing OSS sound device path.

SUBST_CLASSES+=		ins_base
SUBST_STAGE.ins_base=	pre-configure
SUBST_FILES.ins_base=	DEFAULTS/Defaults.*
SUBST_SED.ins_base=		-e "/^INS_BASE=/d"
SUBST_MESSAGE.ins_base=	Fixing INS_BASE.

do-configure:
	cd ${WRKSRC}/RULES;						\
	for suffix in netbsd-cc.rul netbsd-gcc.rul; do			\
		if [ ! -f ${MACHINE}-$$suffix ]; then			\
			ln -sf i386-$$suffix ${MACHINE}-$$suffix;	\
		fi;							\
	done;								\
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} config

post-build:
	cd ${WRKSRC};							\
	for manpage in cdda2wav/cdda2wav.1 mkisofs/mkisofs.8; do	\
		tbl $${manpage} > $${manpage}.tmp;			\
		mv -f $${manpage}.tmp $${manpage};			\
	done

do-install:
	for program in btcflash cdda2wav cdrecord mkisofs		\
		readcd scgcheck scgskeleton; do				\
	cd ${WRKSRC}/$${program};					\
		${INSTALL_PROGRAM} OBJ/*/$${program} 			\
			${DESTDIR}${PREFIX}/bin;			\
	done
	for program in cdda2mp3 cdda2ogg; do				\
		${INSTALL_SCRIPT} ${WRKSRC}/cdda2wav/$${program} 	\
			${DESTDIR}${PREFIX}/bin;			\
		${INSTALL_MAN} ${WRKSRC}/cdda2wav/$${program}.1 	\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;		\
	done
	for program in btcflash cdda2wav cdrecord	\
		readcd scgcheck; do	\
		${INSTALL_MAN} ${WRKSRC}/$${program}/$${program}.1 	\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;		\
	done
	for program in mkisofs; do				\
		${INSTALL_MAN} ${WRKSRC}/$${program}/$${program}.8 	\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8;		\
	done
	cd ${WRKSRC}/mkisofs/diag;					\
		for f in devdump isodebug isodump isoinfo isovfy; do	\
			${INSTALL_PROGRAM} OBJ/*/$$f ${DESTDIR}${PREFIX}/bin; \
			${INSTALL_MAN} $$f.8 \
				${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/$$f.8; \
		done
	${INSTALL_DATA} ${WRKSRC}/libsiconv/tables/[cik]* \
		${DESTDIR}${PREFIX}/lib/siconv
	${RM} ${DESTDIR}${PREFIX}/lib/siconv/*mk
	${INSTALL_DATA} ${WRKSRC}/cdda2wav/README* \
		${DESTDIR}${PREFIX}/share/doc/cdrtools/cdda2wav
	${INSTALL_DATA} ${WRKSRC}/cdrecord/README* \
		${DESTDIR}${PREFIX}/share/doc/cdrtools/cdrecord
	${INSTALL_DATA} ${WRKSRC}/mkisofs/README* \
		${DESTDIR}${PREFIX}/share/doc/cdrtools/mkisofs
	${INSTALL_DATA} ${WRKSRC}/cdrecord/cdrecord.dfl \
		${DESTDIR}${PREFIX}/share/examples/cdrtools/cdrecord

.include "../../mk/oss.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
