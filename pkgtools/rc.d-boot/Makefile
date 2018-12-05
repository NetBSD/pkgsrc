# $NetBSD: Makefile,v 1.1 2018/12/05 19:23:04 schmonz Exp $
#

PKGNAME=		rc.d-boot-20181205
CATEGORIES=		pkgtools

MAINTAINER=		schmonz@NetBSD.org
COMMENT=		Run package rc.d scripts at boot on any supported OS

ONLY_FOR_PLATFORM=	Darwin-*-*

DEPENDS+=		rc.subr-[0-9]*:../../pkgtools/rc.subr
DEPENDS+=		rcorder-[0-9]*:../../pkgtools/rcorder

NO_CHECKSUM=		yes
NO_BUILD=		yes

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	rc.d-boot org.pkgsrc.rc.d-boot.plist
SUBST_VARS.paths=	PREFIX RCD_SCRIPTS_DIR

CONF_FILES+=		${PREFIX}/share/examples/${PKGBASE}/org.pkgsrc.rc.d-boot.plist \
			/Library/LaunchDaemons/org.pkgsrc.rc.d-boot.plist

INSTALLATION_DIRS=	sbin share/examples/${PKGBASE}

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/org.pkgsrc.rc.d-boot.plist ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d-boot ${DESTDIR}${PREFIX}/sbin/

.include "../../mk/bsd.pkg.mk"
