# $NetBSD: Makefile,v 1.1.1.1 2001/07/06 22:18:43 zuntum Exp $
#

DISTNAME=	service-config-0.51
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/service-config/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.superscript.com/service-config/intro.html
COMMENT=	Utility to create and configure svscan service directories

DEPENDS+=	daemontools-*:../../sysutils/daemontools

ALL_TARGET=	it
INSTALL_TARGET=	setup check

RESTRICTED=     "Possibly inherited DJB-style license would prohibit distribution	\
		 of modified binary packages"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}

post-patch:
	${ECHO} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	${ECHO} "${CC} ${STRIPFLAG}" > ${WRKSRC}/conf-ld
	${ECHO} "${PREFIX}" > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
