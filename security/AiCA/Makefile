# $NetBSD: Makefile,v 1.3.6.1 2004/07/30 15:53:21 agc Exp $
#

DISTNAME=	AiCA-0.71.1
CATEGORIES=	security
MASTER_SITES=	http://mars.elcom.nitech.ac.jp/security/

MAINTAINER=	tech-pkg@jp.NetBSD.org
HOMEPAGE=	http://mars.elcom.nitech.ac.jp/security/
COMMENT=	Manage Certification Authority,PKI viewer/converter/verification

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

RESTRICTED=             "Source code redistribution is not permitted.consult okuno@mars.elcom.nitech.ac.jp."
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/AiCA
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README.j \
		${WRKSRC}/README ${WRKSRC}/sample.list.csv \
		${PREFIX}/share/doc/AiCA

.include "../../mk/bsd.pkg.mk"
