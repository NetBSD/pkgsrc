# $NetBSD: Makefile,v 1.6 2004/02/19 18:50:01 wiz Exp $
#

DISTNAME=	waste-source
PKGNAME=	waste-1.0
CATEGORIES=	net
# AOL pulled the plug on Nullsoft
# MASTER_SITES=	http://www.nullsoft.com/free/waste/
# HOMEPAGE=	http://www.nullsoft.com/free/waste/
MASTER_SITES=	http://slackerbitch.free.fr/waste/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.dhorrocks2003.pwp.blueyonder.co.uk/
COMMENT=	Secure file sharing network

WRKSRC=		${WRKDIR}/waste

RESTRICTED=     Unclear legal status: AOL claims Nullsoft did not \
		release the software at all, while others regard it as \
		licensed under the GPL

NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

USE_BUILDLINK2=		yes

MAKE_ENV+=	LDFLAGS="-L${BUILDLINK_PREFIX.pthread}/lib -Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.pthread}/lib"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wastesrv ${PREFIX}/sbin/wastesrv
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/waste
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/waste

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
