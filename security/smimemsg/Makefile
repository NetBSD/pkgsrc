# $NetBSD: Makefile,v 1.3 2003/03/29 12:42:25 jmmv Exp $
#

DISTNAME=	smimemsg141
PKGNAME=	smimemsg-1.4.1
WRKSRC=		${WRKDIR}/smimemsg
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg@jp.netbsd.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	generate and read S/MIME messages

GNU_CONFIGURE=	YES

RESTRICTED=             "Source code redistribution is not permitted.consult okuno@mars.elcom.nitech.ac.jp."
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smimemsg
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README \
	${WRKSRC}/README-j ${PREFIX}/share/doc/smimemsg

.include "../../mk/bsd.pkg.mk"
