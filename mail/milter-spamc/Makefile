# $NetBSD: Makefile,v 1.1.1.1 2003/12/11 17:32:23 manu Exp $
#

DISTNAME=		milter-spamc-0.10
CATEGORIES=		mail
MASTER_SITES=		http://www.snert.com/Software/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		manu@netbsd.org
HOMEPAGE=		http://www.snert.com/Software/download/
COMMENT=		Yet another SpamAssassin Milter

WRKSRC=			${WRKDIR}/com/snert/src/milter-spamc
GNU_CONFIGURE=		yes
MAKEFILE=		makefile
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/milter-spamc.sh ${PREFIX}/etc/rc.d
	${INSTALL_PROGRAM} ${WRKSRC}/milter-spamc ${PREFIX}/sbin
	${INSTALL} -d -o smmsp -g smmsp /var/milter-spamc

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mail/libsnert/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
