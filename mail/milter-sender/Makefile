# $NetBSD: Makefile,v 1.1.1.1 2003/10/27 17:57:33 manu Exp $
#

DISTNAME=		milter-sender-0.41
DISTFILES=		libsnert-1.23.tgz milter-sender-0.41.tgz
CATEGORIES=		mail
MASTER_SITES=		http://www.snert.com/Software/download/

MAINTAINER=		manu@netbsd.org
HOMEPAGE=		http://www.snert.com/Software/download/
COMMENT=		Real-time sender's e-mail validity check

WRKSRC=			${WRKDIR}/com/snert/src/milter-sender
GNU_CONFIGURE=		yes
MAKEFILE=		makefile
#CFLAGS+=		-I${WRKDIR}
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/milter-sender.sh ${PREFIX}/etc/rc.d
	${INSTALL_PROGRAM} ${WRKSRC}/milter-sender ${PREFIX}/sbin
	${INSTALL} -d -o smmsp -g smmsp /var/milter-sender

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mail/libsnert/buildlink2.mk"
.include "../../databases/db3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
