# $NetBSD: Makefile,v 1.5 2004/04/21 21:47:19 wiz Exp $

DISTNAME=	cdrtools-2.01a24
PKGNAME=	cdrtools-ossdvd-2.01.1.24
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/alpha/

PATCHFILES=	cdrtools-2.01a24-ossdvd.patch-rs.bz2
PATCH_SITES=	ftp://ftp.crashrecovery.org/pub/linux/cdrtools/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://crashrecovery.org/oss-dvd.html
COMMENT=	Software for creating ISO9660 images and writing CDs/CD-RWs/DVDs

CONFLICTS=	mkisofs-[0-9]* cdrecord-* cdrtools-*

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/cdrtools-2.01
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
TBL?=			tbl

.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM=	r:/opt/schily
BUILDLINK_TRANSFORM+=	r:/opt/schily
.endif

# avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""
MAKE_ENV+=      MAKEPROG="gmake"
MAKE_ENV+=	COPTX="${CFLAGS}"
MAKE_ENV+=	LDOPTX="${LDFLAGS}"

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
MESSAGE_SUBST+=	PKGNAME_NOREV=${PKGNAME_NOREV}
MESSAGE_SUBST+=	CDRECORD_CONF=${CDRECORD_CONF}
.endif

CDRECORD_CONF_FILES=	cdrecord/defaults.c cdrecord/cdrecord.1
CDRECORD_CONF_FILES+=	readcd/readcd.1

post-patch:
	@cd ${WRKSRC}; for file in ${CDRECORD_CONF_FILES}; do		\
		${MV} ${WRKSRC}/$$file ${WRKSRC}/$${file}.old &&	\
		${SED} -e 's|@CDRECORD_CONF@|${CDRECORD_CONF}|'	\
			${WRKSRC}/$${file}.old > ${WRKSRC}/$$file;	\
	done

do-configure:
	cd ${WRKSRC}/RULES;						\
	for suffix in netbsd-cc.rul netbsd-gcc.rul; do			\
		if [ ! -f ${MACHINE}-$$suffix ]; then			\
			${LN} -sf i386-$$suffix ${MACHINE}-$$suffix;	\
		fi;							\
	done

post-build:
	cd ${WRKSRC};							\
	for file in cdda2wav/cdda2wav.1 mkisofs/mkisofs.8; do		\
		${TBL} $${file} > $${file}.tmp;				\
		${MV} -f $${file}.tmp $${file};				\
	done

do-install:
	cd ${WRKSRC}/cdda2wav;						\
		${INSTALL_PROGRAM} OBJ/*/cdda2wav ${PREFIX}/bin;	\
		${INSTALL_MAN} cdda2wav.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} OBJ/*/cdrecord ${PREFIX}/bin;	\
		${INSTALL_MAN} cdrecord.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/mkisofs;						\
		${INSTALL_PROGRAM} OBJ/*/mkisofs ${PREFIX}/bin;		\
		${INSTALL_MAN} mkisofs.8 ${PREFIX}/man/man8
	cd ${WRKSRC}/mkisofs/diag;					\
		for f in devdump isodump isoinfo isovfy; do		\
			${INSTALL_PROGRAM} OBJ/*/$$f ${PREFIX}/bin;	\
			${INSTALL_MAN} isoinfo.8 ${PREFIX}/man/man8/$$f.8; \
		done
	cd ${WRKSRC}/readcd;						\
		${INSTALL_PROGRAM} OBJ/*/readcd ${PREFIX}/bin;		\
		${INSTALL_MAN} readcd.1 ${PREFIX}/man/man1

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
