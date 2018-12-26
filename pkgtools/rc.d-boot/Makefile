# $NetBSD: Makefile,v 1.6 2018/12/26 00:43:55 schmonz Exp $
#

PKGNAME=		rc.d-boot-20181226
CATEGORIES=		pkgtools

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Run package rc.d scripts at boot on any supported OS
LICENSE=		2-clause-bsd

ONLY_FOR_PLATFORM=	# empty by default

.include "../../mk/bsd.prefs.mk"

.if exists(/sbin/rcorder)
RCORDER=		/sbin/rcorder
.else
DEPENDS+=		rc.subr>=20181226:../../pkgtools/rc.subr
DEPENDS+=		rcorder-[0-9]*:../../pkgtools/rcorder
RCORDER=		${PREFIX}/sbin/rcorder
.endif

NO_CHECKSUM=		yes
NO_BUILD=		yes

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	rc.d-boot
SUBST_FILES.paths+=	org.pkgsrc.rc.d-boot.plist \
			pkgsrc-rc.d-boot.service
SUBST_VARS.paths=	GREP PREFIX RCD_SCRIPTS_DIR RCORDER

FILES_SUBST+=		RCDBOOT_STYLE=${RCDBOOT_STYLE:Q}
FILES_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR:Q}

EGDIR=			share/examples/${PKGBASE}

.if ${OPSYS} == "Darwin" && exists (/Library/LaunchDaemons)
ONLY_FOR_PLATFORM+=	${OPSYS}-*-*
RCDBOOT_STYLE=		darwin-launchd
CONF_FILES+=		${PREFIX}/${EGDIR}/org.pkgsrc.rc.d-boot.plist \
			/Library/LaunchDaemons/org.pkgsrc.rc.d-boot.plist
.elif ${OPSYS} == "FreeBSD" && exists(/etc/rc.d)
ONLY_FOR_PLATFORM+=	${OPSYS}-*-*
RCDBOOT_STYLE=		freebsd-native
.elif ${OPSYS} == "Linux" && exists(/etc/systemd/system)
ONLY_FOR_PLATFORM+=	${OPSYS}-*-*
RCDBOOT_STYLE=		linux-systemd
CONF_FILES+=		${PREFIX}/${EGDIR}/pkgsrc-rc.d-boot.service \
			/etc/systemd/system/pkgsrc-rc.d-boot.service
.elif ${OPSYS} == "NetBSD" && exists(/etc/rc.d)
ONLY_FOR_PLATFORM+=	${OPSYS}-*-*
RCDBOOT_STYLE=		netbsd-native
.elif ${OPSYS} == "OpenBSD" && exists(/etc/rc.d/rc.subr)
ONLY_FOR_PLATFORM+=	${OPSYS}-*-*
RCDBOOT_STYLE=		openbsd-rcd
.else
NOT_FOR_PLATFORM+=	${OPSYS}-*-*
.endif

BUILD_DEFS+=		RCD_SCRIPTS_DIR
INSTALLATION_DIRS=	sbin ${EGDIR}

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
.	for i in org.pkgsrc.rc.d-boot.plist \
		pkgsrc-rc.d-boot.service
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/${EGDIR}/
.	endfor
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d-boot ${DESTDIR}${PREFIX}/sbin/

.include "../../mk/bsd.pkg.mk"
