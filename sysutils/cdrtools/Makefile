# $NetBSD: Makefile,v 1.126 2022/08/09 12:08:33 jperkin Exp $

DISTNAME=	schily-2021-09-18
PKGNAME=	cdrtools-3.02a10
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/schilytools/
COMMENT=	Software for creating ISO9660 images and writing CD/DVD/Blu-ray
LICENSE=	cddl-1.0 AND gnu-gpl-v2 AND gnu-lgpl-v2.1 AND 2-clause-bsd

MAKE_JOBS_SAFE=	no

LDFLAGS.Darwin+=	-liconv

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	smake>=1.3nb11:../../devel/smake
SMAKE=		MAKEFLAGS= smake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}
# Honor CPPFLAGS, CFLAGS and LDFLAGS
MAKE_FLAGS+=	CPPOPTX=${CPPFLAGS:Q} COPTX=${CFLAGS:Q} LDOPTX=${LDFLAGS:Q}

# The default location is /etc/default/cdrecord
# We patch the documentation appropriately. Additionally, we also install
# INSTALL.pkgsrc stating the reasons we do this, as required by the license.
CONF_FILES=	${PREFIX}/share/examples/cdrtools/cdrecord ${PKG_SYSCONFDIR}/cdrecord
SPECIAL_PERMS+=	${PREFIX}/share/examples/cdrtools/cdrecord ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644
AUTO_MKDIRS=	yes

# Configure config file location
SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	pre-configure
SUBST_FILES.fix+=	cdrecord/cdrecord.1
SUBST_FILES.fix+=	cdrecord/cdrecord.dfl
SUBST_SED.fix=		-e "s,/etc/default/cdrecord,${PKG_SYSCONFDIR}/cdrecord,g"
SUBST_MESSAGE.fix=	Replace defaults file paths.

# Configure INSTALL.pkgsrc (formerly displayed as MESSAGE)
SUBST_CLASSES+=		install
SUBST_STAGE.install=	post-configure
SUBST_MESSAGE.install=	Preparing INSTALL.pkgsrc file ...
SUBST_FILES.install=	${WRKDIR}/INSTALL.pkgsrc
SUBST_VARS.install=	PKGNAME_NOREV
SUBST_VARS.install+=	PKG_SYSCONFDIR
SUBST_VARS.install+=	LOCALBASE

# Shared platform specific code for schilytools (provided by smake package)
.include "../../devel/smake/Makefile.common"

do-configure:
	${CP} ${FILESDIR}/INSTALL.pkgsrc ${WRKDIR}
	cd ${WRKSRC}/inc && ${SMAKE} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && 						\
	for library in libschily libdeflt libcdrdeflt libedc libfile	\
	    libfind libhfs_iso libmdigest libscg libscgcmd librscg	\
	    libparanoia libsiconv;					\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/btcflash && ${SMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC}/cdda2wav && ${SMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC}/cdrecord && ${SMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC}/mkisofs && ${SMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC}/mkisofs/diag && ${SMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC}/readcd && ${SMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC}/scgcheck && ${SMAKE} ${MAKE_FLAGS}
	cd ${WRKSRC}/scgskeleton && ${SMAKE} ${MAKE_FLAGS}

# Process tables in manpage
.if !empty(USE_TOOLS:Mtbl)
post-build:
	cd ${WRKSRC} && if ${TEST} -f star/pkgsrc_tbl.done; then :;	\
	else								\
		${TBL} cdda2wav/cdda2wav.1 >cdda2wav/cdda2wav.1.tmp &&	\
		${MV} -f cdda2wav/cdda2wav.1.tmp cdda2wav/cdda2wav.1 &&	\
		${TBL} mkisofs/mkisofs.8 >mkisofs/mkisofs.8.tmp &&	\
		${MV} -f mkisofs/mkisofs.8.tmp mkisofs/mkisofs.8 &&	\
		${TOUCH} star/pkgsrc_tbl.done;				\
	fi
.endif

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
	for program in btcflash cdda2wav cdrecord			\
		readcd scgcheck; do					\
		${INSTALL_MAN} ${WRKSRC}/$${program}/$${program}.1 	\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;		\
	done
	for program in mkisofs; do					\
		${INSTALL_MAN} ${WRKSRC}/$${program}/$${program}.8 	\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man8;		\
	done
	cd ${WRKSRC}/mkisofs/diag;					\
		for f in devdump isodebug isodump isoinfo isovfy; do	\
			${INSTALL_PROGRAM} OBJ/*/$$f ${DESTDIR}${PREFIX}/bin; \
			${INSTALL_MAN} $$f.8 \
				${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/$$f.8; \
		done
	${INSTALL_DATA} ${WRKSRC}/libsiconv/tables/[cik]*		\
		${DESTDIR}${PREFIX}/lib/siconv
	${RM} ${DESTDIR}${PREFIX}/lib/siconv/*mk
	${INSTALL_DATA} ${WRKSRC}/cdda2wav/README*			\
		${DESTDIR}${PREFIX}/share/doc/cdrtools/cdda2wav
	${INSTALL_DATA} ${WRKSRC}/cdrecord/README*			\
		${DESTDIR}${PREFIX}/share/doc/cdrtools/cdrecord
	${INSTALL_DATA} ${WRKSRC}/mkisofs/README*			\
		${DESTDIR}${PREFIX}/share/doc/cdrtools/mkisofs
	${INSTALL_DATA} ${WRKSRC}/cdrecord/cdrecord.dfl			\
		${DESTDIR}${PREFIX}/share/examples/cdrtools/cdrecord
	${INSTALL_DATA} ${WRKDIR}/INSTALL.pkgsrc			\
		${DESTDIR}${PREFIX}/share/doc/cdrtools/INSTALL.pkgsrc

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
