# $NetBSD: Makefile,v 1.4 2004/04/24 22:56:32 snj Exp $
#

DISTNAME=		milter-sender-0.41
CATEGORIES=		mail
MASTER_SITES=		http://www.snert.com/Software/download/
DISTFILES=		libsnert-1.23.tgz milter-sender-0.41.tgz

MAINTAINER=		manu@NetBSD.org
HOMEPAGE=		http://www.snert.com/Software/download/
COMMENT=		Real-time sender's e-mail validity check

WRKSRC=			${WRKDIR}/com/snert/src/milter-sender
GNU_CONFIGURE=		yes
MAKEFILE=		makefile
#CFLAGS+=		-I${WRKDIR}
USE_BUILDLINK3=		yes

LICENSE=		snert-license
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/milter-sender.sh ${PREFIX}/etc/rc.d
	${INSTALL_PROGRAM} ${WRKSRC}/milter-sender ${PREFIX}/sbin
	${INSTALL} -d -o smmsp -g smmsp /var/milter-sender

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libsnert/buildlink3.mk"
.include "../../databases/db3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
