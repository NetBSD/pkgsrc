# $NetBSD: Makefile,v 1.1.1.1 2001/03/14 03:05:08 jun Exp $
#

DISTNAME=	smimemsg131
PKGNAME=	smimemsg-1.3.1
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg@jp.netbsd.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	generate and read S/MIME messages

WRKSRC=		${WRKDIR}/smimemsg
GNU_CONFIGURE=	YES

RESTRICTED=             "Source code redistribution is not permitted.consult okuno@mars.elcom.nitech.ac.jp."
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smimemsg
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README \
	${WRKSRC}/README-j ${PREFIX}/share/doc/smimemsg

.include "../../mk/bsd.pkg.mk"
