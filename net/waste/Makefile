# $NetBSD: Makefile,v 1.13 2006/10/04 21:53:18 wiz Exp $
#

DISTNAME=	waste-source
PKGNAME=	waste-1.0
CATEGORIES=	net
# AOL pulled the plug on Nullsoft
# MASTER_SITES=	http://www.nullsoft.com/free/waste/
# HOMEPAGE=	http://www.nullsoft.com/free/waste/
MASTER_SITES=	http://slackerbitch.free.fr/waste/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://waste.2mbit.com/index2.html
COMMENT=	Secure file sharing network

WRKSRC=		${WRKDIR}/waste

RESTRICTED=     Unclear legal status: AOL claims Nullsoft did not \
		release the software at all, while others regard it as \
		licensed under the GPL

NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
LDFLAGS+=	-lmd
.endif

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wastesrv ${PREFIX}/sbin/wastesrv
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/waste
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/waste

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
