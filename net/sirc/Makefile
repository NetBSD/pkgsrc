# $NetBSD: Makefile,v 1.8 1998/08/20 15:17:19 tsarna Exp $

DISTNAME=	sirc-2.21
CATEGORIES=	net
MASTER_SITES=	http://www.eleves.ens.fr:8080/home/espel/sirc/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.eleves.ens.fr:8080/home/espel/sirc/

RUN_DEPENDS=    ${PREFIX}/bin/perl:../../lang/perl5

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
