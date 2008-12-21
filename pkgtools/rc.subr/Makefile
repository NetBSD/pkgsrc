# $NetBSD: Makefile,v 1.18 2008/12/21 00:03:32 adrianp Exp $
#

DISTNAME=		rc.subr-20081208
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Portable NetBSD rc.subr implementation for pkgsrc

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-[0-4].*-* Interix-*-*
ONLY_FOR_PLATFORM+=	Linux-*-* SunOS-*-*
ONLY_FOR_PLATFORM+=	QNX-*-*

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_MTREE=		yes

CHECK_FILES_SUPPORTED=	no

PLIST_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR:S/^\///}

CONF_FILES+=		${PREFIX}etc/rc.conf.example ${PREFIX}etc/rc.conf

INSTALLATION_DIRS=	etc

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_DATA} ${WRKSRC}/rc.conf.example ${PREFIX}etc/rc.conf.example
	${INSTALL_DATA} ${WRKSRC}/rc.subr ${PREFIX}etc/rc.subr
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/DAEMON ${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/LOGIN ${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/NETWORKING ${PREFIX}${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/SERVERS ${PREFIX}${RCD_SCRIPTS_DIR}

.include "../../mk/bsd.pkg.mk"

# if you change this, be sure to include a trailing /
PREFIX:=		/
