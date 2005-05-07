# $NetBSD: Makefile,v 1.5.8.1 2005/05/07 00:26:23 snj Exp $
#

DISTNAME=		milter-spamc-0.10
CATEGORIES=		mail
MASTER_SITES=		http://www.snert.com/Software/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://www.snert.com/Software/download/
COMMENT=		Yet another SpamAssassin Milter

WRKSRC=			${WRKDIR}/com/snert/src/milter-spamc
GNU_CONFIGURE=		yes
MAKEFILE=		makefile
USE_BUILDLINK3=		yes

LICENSE=		snert-license
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/milter-spamc.sh ${PREFIX}/etc/rc.d
	${INSTALL_PROGRAM} ${WRKSRC}/milter-spamc ${PREFIX}/sbin
	${INSTALL} -d -o smmsp -g smmsp /var/milter-spamc

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libsnert/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
