# $NetBSD: Makefile,v 1.5 2004/06/27 13:42:46 grant Exp $
#

DISTNAME=	AiCA-0.71.1
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg@jp.NetBSD.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	Manage Certification Authority,PKI viewer/converter/verification

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

RESTRICTED=             "Source code redistribution is not permitted. consult okuno@mars.elcom.nitech.ac.jp."
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/AiCA
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README.j \
		${WRKSRC}/README ${WRKSRC}/sample.list.csv \
		${PREFIX}/share/doc/AiCA

.include "../../mk/bsd.pkg.mk"
