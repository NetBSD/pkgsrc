# $NetBSD: Makefile,v 1.5 2004/04/24 22:57:16 snj Exp $
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

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/milter-spamc.sh ${PREFIX}/etc/rc.d
	${INSTALL_PROGRAM} ${WRKSRC}/milter-spamc ${PREFIX}/sbin
	${INSTALL} -d -o smmsp -g smmsp /var/milter-spamc

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libsnert/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
