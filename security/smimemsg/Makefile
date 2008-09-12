# $NetBSD: Makefile,v 1.13 2008/09/12 11:45:41 gdt Exp $
#

DISTNAME=	smimemsg15
PKGNAME=	smimemsg-1.5
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	Generate and read S/MIME messages

WRKSRC=		${WRKDIR}/smimemsg
GNU_CONFIGURE=	yes

# unreachable homepage, unfetchable distfile
LICENSE=	generic-nonlicense
RESTRICTED=		Source code redistribution is not permitted.consult okuno@mars.elcom.nitech.ac.jp.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/smimemsg
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README \
	${WRKSRC}/README-j ${PREFIX}/share/doc/smimemsg

.include "../../mk/bsd.pkg.mk"
