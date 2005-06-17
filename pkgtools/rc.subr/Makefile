# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:30 jlam Exp $
#

DISTNAME=		rc.subr-20041011
PKGREVISION=		1
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

INSTALLATION_DIRS=	etc

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

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
