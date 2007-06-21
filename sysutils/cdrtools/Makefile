# $NetBSD: Makefile,v 1.17 2007/06/21 18:16:16 wiz Exp $

DISTNAME=	cdrtools-2.01.01a27
PKGNAME=	cdrtools-2.01.01.27
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/alpha/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/cdrecord.html
COMMENT=	Software for creating ISO9660 images and writing CDs/CD-RWs

CONFLICTS=	mkisofs-[0-9]* cdrtools-ossdvd-[0-9]* cdrecord-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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
SUBST_FILES.fix=	btcflash/btcflash.1
SUBST_FILES.fix+=	cdrecord/cdrecord.1
SUBST_FILES.fix+=	cdrecord/defaults.c
SUBST_FILES.fix+=	mkisofs/diag/isoinfo.8
SUBST_FILES.fix+=	readcd/readcd.1
SUBST_FILES.fix+=	scgcheck/scgcheck.1
SUBST_SED.fix=		-e "s,/etc/default/cdrecord,${CDRECORD_CONF},g"
SUBST_MESSAGE.fix=	Fixing paths.

post-extract:
	ln -s Defaults.freebsd ${WRKSRC}/DEFAULTS/Defaults.dragonfly
	ln -s Defaults.freebsd ${WRKSRC}/DEFAULTS_ENG/Defaults.dragonfly

do-configure:
	cd ${WRKSRC}/RULES;						\
	for suffix in netbsd-cc.rul netbsd-gcc.rul; do			\
		if [ ! -f ${MACHINE}-$$suffix ]; then			\
			ln -sf i386-$$suffix ${MACHINE}-$$suffix;	\
		fi;							\
	done

post-build:
	cd ${WRKSRC};							\
	for manpage in cdda2wav/cdda2wav.1 mkisofs/mkisofs.8; do	\
		tbl $${manpage} > $${manpage}.tmp;			\
		mv -f $${manpage}.tmp $${manpage};			\
	done

do-install:
	cd ${WRKSRC}/cdda2wav;						\
		${INSTALL_PROGRAM} OBJ/*/cdda2wav ${DESTDIR}${PREFIX}/bin;	\
		${INSTALL_MAN} cdda2wav.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} OBJ/*/cdrecord ${DESTDIR}${PREFIX}/bin;	\
		${INSTALL_MAN} cdrecord.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/mkisofs;						\
		${INSTALL_PROGRAM} OBJ/*/mkisofs ${DESTDIR}${PREFIX}/bin;		\
		${INSTALL_MAN} mkisofs.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	cd ${WRKSRC}/mkisofs/diag;					\
		for f in devdump isodump isoinfo isovfy; do		\
			${INSTALL_PROGRAM} OBJ/*/$$f ${DESTDIR}${PREFIX}/bin;	\
			${INSTALL_MAN} isoinfo.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/$$f.8; \
		done
	cd ${WRKSRC}/readcd;						\
		${INSTALL_PROGRAM} OBJ/*/readcd ${DESTDIR}${PREFIX}/bin;		\
		${INSTALL_MAN} readcd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
