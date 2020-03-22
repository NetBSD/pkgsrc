# $NetBSD: Makefile,v 1.34 2020/03/22 13:21:05 tnn Exp $
#

PKGNAME=		rc.subr-20181226
CATEGORIES=		pkgtools

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Portable NetBSD rc.subr implementation for pkgsrc
LICENSE=		original-bsd

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-[0-4].*-* Interix-*-* IRIX*-*-*
ONLY_FOR_PLATFORM+=	Linux-*-* OpenBSD-*-* QNX-*-* SunOS-*-*

NO_BUILD=		yes
NO_CONFIGURE=		yes
NOT_FOR_UNPRIVILEGED=	yes

CHECK_FILES_SUPPORTED=	no
BUILD_DEFS+=		RCD_SCRIPTS_DIR

PLIST_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR:S/^\///}

CONF_FILES+=		etc/rc.conf.example etc/rc.conf

INSTALLATION_DIRS=	etc ${RCD_SCRIPTS_DIR:S/^\///}

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/rc.conf.example ${DESTDIR}${PREFIX}etc/rc.conf.example
	${INSTALL_DATA} ${WRKSRC}/rc.subr ${DESTDIR}${PREFIX}etc/rc.subr
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/DAEMON ${DESTDIR}${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/LOGIN ${DESTDIR}${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/NETWORKING ${DESTDIR}${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/SERVERS ${DESTDIR}${PREFIX}${RCD_SCRIPTS_DIR}

.include "../../mk/bsd.pkg.mk"

# if you change this, be sure to include a trailing /
PREFIX:=		/
