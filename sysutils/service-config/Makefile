# $NetBSD: Makefile,v 1.6 2005/03/13 03:25:44 schmonz Exp $
#

DISTNAME=	service-config-0.51
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/service-config/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.superscript.com/service-config/intro.html
COMMENT=	Utility to create and configure svscan service directories

DEPENDS+=	daemontools-[0-9]*:../../sysutils/daemontools

BUILD_TARGET=	it
INSTALL_TARGET=	setup check

RESTRICTED=     "Possibly inherited DJB-style license would prohibit distribution	\
		 of modified binary packages"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}

do-configure:
	${ECHO} ${CC:Q} ${CFLAGS:Q} > ${WRKSRC}/conf-cc
	${ECHO} ${CC:Q} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
