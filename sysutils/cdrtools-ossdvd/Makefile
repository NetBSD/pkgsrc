# $NetBSD: Makefile,v 1.31 2008/01/29 18:24:30 tnn Exp $

DISTNAME=	cdrtools-2.01.01a05
PKGNAME=	cdrtools-ossdvd-2.01.1.36
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/alpha/
EXTRACT_SUFX=	.tar.bz2

PATCHFILES=	cdrtools-2.01.01a05-ossdvd.patch.bz2
PATCH_SITES=	ftp://ftp.crashrecovery.org/pub/linux/cdrtools/ \
		http://crashrecovery.org/oss-dvd/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://crashrecovery.org/oss-dvd.html
COMMENT=	Software for creating ISO9660 images and writing CDs/CD-RWs/DVDs

CONFLICTS=	mkisofs-[0-9]* cdrecord-[0-9]* cdrtools-[a-z0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/cdrtools-2.01.01
USE_TOOLS+=	gmake tbl

.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM+=	rmdir:/opt/schily
.endif

# avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=	ARCH=""
MAKE_ENV+=	MAKEPROG="gmake"
MAKE_ENV+=	COPTX=${CFLAGS:Q}
MAKE_ENV+=	LDOPTX=${LDFLAGS:Q}

# if we're using a gcc which is named gcc, we need to set CCOM=gcc
# in MAKE_ENV so the make infrastructure picks the right options.
.if !empty(CC:M*gcc*)
MAKE_ENV+=	CCOM="gcc"
.endif

# allow us to override the default /etc/default/cdrecord by patching
# the documentation appropriately. Additionally, we also provide a
# MESSAGE stating the reasons we do this, as required by the license.
CDRECORD_CONF?=	${PKG_SYSCONFDIR}/cdrecord.conf

.if ${CDRECORD_CONF} != "/etc/default/cdrecord"
MESSAGE_SRC+=	MESSAGE.cdrecord.conf
MESSAGE_SUBST+=	PKGNAME_NOREV=${PKGNAME_NOREV:Q}
MESSAGE_SUBST+=	CDRECORD_CONF=${CDRECORD_CONF:Q}
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	cdrecord/defaults.c cdrecord/cdrecord.1 \
			readcd/readcd.1
SUBST_SED.fix=		-e "s,@CDRECORD_CONF@,${CDRECORD_CONF},g"
SUBST_MESSAGE.fix=	Fixing paths.

post-extract:
	${LN} -s Defaults.freebsd ${WRKSRC}/DEFAULTS/Defaults.dragonfly
	${LN} -s Defaults.freebsd ${WRKSRC}/DEFAULTS_ENG/Defaults.dragonfly
	${CP} ${WRKSRC}/RULES/power-macintosh-darwin-cc.rul \
		${WRKSRC}/RULES/i386-darwin-cc.rul
	${CP} ${WRKSRC}/RULES/power-macintosh-darwin-gcc.rul \
		${WRKSRC}/RULES/i386-darwin-gcc.rul

do-configure:
	cd ${WRKSRC}/RULES;						\
	for suffix in netbsd-cc.rul netbsd-gcc.rul; do			\
		if [ ! -f ${MACHINE}-$$suffix ]; then			\
			${LN} -sf i386-$$suffix ${MACHINE}-$$suffix;	\
		fi;							\
	done
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${MAKE_PROGRAM} config

post-build:
	cd ${WRKSRC};							\
	for manpage in cdda2wav/cdda2wav.1 mkisofs/mkisofs.8; do	\
		${TBL} $${manpage} > $${manpage}.tmp;			\
		${MV} -f $${manpage}.tmp $${manpage};			\
	done

do-install:
	cd ${WRKSRC}/cdda2wav;						\
		${INSTALL_PROGRAM} OBJ/*/cdda2wav ${PREFIX}/bin;	\
		${INSTALL_MAN} cdda2wav.1 ${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} OBJ/*/cdrecord ${PREFIX}/bin;	\
		${INSTALL_MAN} cdrecord.1 ${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/mkisofs;						\
		${INSTALL_PROGRAM} OBJ/*/mkisofs ${PREFIX}/bin;		\
		${INSTALL_MAN} mkisofs.8 ${PREFIX}/${PKGMANDIR}/man8
	cd ${WRKSRC}/mkisofs/diag;					\
		for f in devdump isodump isoinfo isovfy; do		\
			${INSTALL_PROGRAM} OBJ/*/$$f ${PREFIX}/bin;	\
			${INSTALL_MAN} isoinfo.8 ${PREFIX}/${PKGMANDIR}/man8/$$f.8; \
		done
	cd ${WRKSRC}/readcd;						\
		${INSTALL_PROGRAM} OBJ/*/readcd ${PREFIX}/bin;		\
		${INSTALL_MAN} readcd.1 ${PREFIX}/${PKGMANDIR}/man1

.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/pset.h)
LDFLAGS+=	-lrt
.endif

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
