# $NetBSD: Makefile,v 1.7 2004/10/11 18:52:56 tv Exp $
#

DISTNAME=		rc.subr-20030706
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Portable NetBSD rc.subr implementation for pkgsrc

ONLY_FOR_PLATFORM=	Darwin-*-* Interix-*-* Linux-*-* SunOS-*-*

NO_BUILD=		# defined
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_MTREE=		# defined
USE_PKGINSTALL=		YES

PLIST_SUBST+=		RCD_SCRIPTS_DIR=${RCD_SCRIPTS_DIR:S/^\///}

CONF_FILES+=		${PREFIX}etc/rc.conf.example ${PREFIX}etc/rc.conf

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${RCD_SCRIPTS_DIR}
	${INSTALL_DATA} ${WRKSRC}/rc.conf.example ${PREFIX}etc/rc.conf.example
	${INSTALL_DATA} ${WRKSRC}/rc.subr ${PREFIX}etc/rc.subr
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/DAEMON ${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/LOGIN ${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/NETWORKING ${RCD_SCRIPTS_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/SERVERS ${RCD_SCRIPTS_DIR}

.include "../../mk/bsd.pkg.mk"

# if you change this, be sure to include a trailing /
PREFIX:=		/
