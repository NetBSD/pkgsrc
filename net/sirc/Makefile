# $NetBSD: Makefile,v 1.6 1998/04/24 09:20:36 agc Exp $

DISTNAME=	sirc-2.21
CATEGORIES=	net
MASTER_SITES=	http://www.eleves.ens.fr:8080/home/espel/sirc/

MAINTAINER=	hubertf@netbsd.org

RUN_DEPENDS=    ${PREFIX}/bin/perl:../../lang/perl5

MAN1=		ssfe.1 sirc.1

NO_CONFIGURE=	yes
NO_BUILD=	yes

### Enter Default IRC-Server here
IRC_SERVER=	us.undernet.org

do-install:
	cd ${WRKSRC} ; ( \
		${ECHO} "y" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "" ; \
		${ECHO} "${PREFIX}/bin/perl" ; \
		${ECHO} "${PREFIX}/bin" ; \
		${ECHO} "y" ; \
		${ECHO} "${PREFIX}/lib/sirc" ; \
		${ECHO} "y" ; \
		${ECHO} "y" ; \
		${ECHO} "n" ; \
		${ECHO} "${PREFIX}/man/man1" ; \
		${ECHO} "${IRC_SERVER}" ; \
		${ECHO} "" ; \
	) | ./install

.include "../../mk/bsd.pkg.mk"
