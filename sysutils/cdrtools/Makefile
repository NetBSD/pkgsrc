# $NetBSD: Makefile,v 1.8 2006/08/28 13:56:22 dsainty Exp $

DISTNAME=	cdrtools-2.01
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/cdrecord.html
COMMENT=	Software for creating ISO9660 images and writing CDs/CD-RWs

CONFLICTS=	mkisofs-[0-9]* cdrtools-ossdvd-[0-9]* cdrecord-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	gmake tbl

.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM+=	rmdir:/opt/schily
.endif

# avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""
MAKE_ENV+=      MAKEPROG="gmake"
MAKE_ENV+=	COPTX=${CFLAGS:M*:Q}
MAKE_ENV+=	LDOPTX=${LDFLAGS:M*:Q}

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

INSTALLATION_DIRS=	bin man/man1 man/man8

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	cdrecord/defaults.c cdrecord/cdrecord.1 \
			readcd/readcd.1
SUBST_SED.fix=		-e "s,@CDRECORD_CONF@,${CDRECORD_CONF},g"
SUBST_MESSAGE.fix=	Fixing paths.

post-extract:
	${CP} ${WRKSRC}/RULES/os-freebsd.id ${WRKSRC}/RULES/os-dragonfly.id

do-configure:
	cd ${WRKSRC}/RULES;						\
	for suffix in netbsd-cc.rul netbsd-gcc.rul; do			\
		if [ ! -f ${MACHINE}-$$suffix ]; then			\
			${LN} -sf i386-$$suffix ${MACHINE}-$$suffix;	\
		fi;							\
	done

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

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
