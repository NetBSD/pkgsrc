# $NetBSD: Makefile,v 1.4 2003/07/17 22:53:51 grant Exp $
#

DISTNAME=	service-config-0.51
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/service-config/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.superscript.com/service-config/intro.html
COMMENT=	Utility to create and configure svscan service directories

DEPENDS+=	daemontools-[0-9]*:../../sysutils/daemontools

ALL_TARGET=	it
INSTALL_TARGET=	setup check

RESTRICTED=     "Possibly inherited DJB-style license would prohibit distribution	\
		 of modified binary packages"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}

post-patch:
	${ECHO} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	${ECHO} "${CC} ${_STRIPFLAG_CC}" > ${WRKSRC}/conf-ld
	${ECHO} "${PREFIX}" > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
