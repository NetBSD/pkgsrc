# $NetBSD: Makefile,v 1.1.1.1 2003/06/19 16:07:10 grant Exp $
#

DISTNAME=		rc.subr-20030619
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Portable NetBSD rc.subr implementation for pkgsrc

ONLY_FOR_PLATFORM=	SunOS-*-*

NO_BUILD=		# defined
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_MTREE=		# defined
USE_PKGINSTALL=	YES

CONF_FILES+=		${PREFIX}etc/rc.conf.example ${PREFIX}etc/rc.conf

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}etc/defaults
	${INSTALL_DATA_DIR} ${PREFIX}etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/rc.conf.example ${PREFIX}etc/rc.conf.example
	${INSTALL_DATA} ${WRKSRC}/rc.subr ${PREFIX}etc/rc.subr
	${INSTALL_DATA} ${WRKSRC}/defaults/rc.conf \
		${PREFIX}etc/defaults/rc.conf
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/DAEMON ${PREFIX}etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/LOGIN ${PREFIX}etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/NETWORKING ${PREFIX}etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/SERVERS ${PREFIX}etc/rc.d

.include "../../mk/bsd.pkg.mk"

# if you change this, be sure to include a trailing /
PREFIX:=			/
