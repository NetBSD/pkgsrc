# $NetBSD: Makefile,v 1.36 2021/08/30 21:45:02 khorben Exp $
#

PKGNAME=		rc.subr-20210830
CATEGORIES=		pkgtools

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Portable NetBSD rc.subr implementation for pkgsrc
LICENSE=		original-bsd

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-[0-4].*-* Interix-*-* IRIX*-*-*
ONLY_FOR_PLATFORM+=	Linux-*-* NetBSD-*-* OpenBSD-*-* QNX-*-* SunOS-*-*

NO_BUILD=		yes
NO_CONFIGURE=		yes

CHECK_FILES_SUPPORTED=	no
BUILD_DEFS+=		SYSCONFBASE
BUILD_DEFS+=		RCD_SCRIPTS_DIR


SUBST_CLASSES+=		subr
SUBST_STAGE.subr=	post-extract
SUBST_FILES.subr=	rc.subr
SUBST_VARS.subr=	SYSCONFBASE

PLIST_SUBST+=		SYSCONFBASE=${SYSCONFBASE:S/^\///}
PLIST_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR:S/^\///}

CONF_FILES+=		${SYSCONFBASE:S/^\///}/rc.conf.example ${SYSCONFBASE:S/^\///}/rc.conf

INSTALLATION_DIRS=	${SYSCONFBASE:S/^\///} ${RCD_SCRIPTS_DIR:S/^\///}

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/rc.conf.example ${DESTDIR}${PREFIX}${SYSCONFBASE}/rc.conf.example
	${INSTALL_DATA} ${WRKSRC}/rc.subr ${DESTDIR}${PREFIX}${SYSCONFBASE}/rc.subr
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/DAEMON ${DESTDIR}${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/LOGIN ${DESTDIR}${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/NETWORKING ${DESTDIR}${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/SERVERS ${DESTDIR}${PREFIX}${RCD_SCRIPTS_DIR}

.include "../../mk/bsd.pkg.mk"

# if you change this, be sure to include a trailing /
PREFIX:=		/
