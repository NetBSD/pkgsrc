# $NetBSD: Makefile,v 1.3 1997/11/11 10:30:40 hubertf Exp $

DISTNAME=	sirc-2.21

MASTER_SITES=	http://www.eleves.ens.fr:8080/home/espel/sirc/
MAINTAINER=	hubertf@netbsd.org
CATEGORIES=	net
RUN_DEPENDS=    ${PREFIX}/bin/perl:${PORTSDIR}/lang/perl5

NO_CONFIGURE=	yes
NO_BUILD=	yes

### Enter Default IRC-Server here
SERVER=		us.undernet.org

do-install:
	cd ${WRKSRC} ; ( \
		echo "y" ; \
		echo "" ; \
		echo "" ; \
		echo "" ; \
		echo "" ; \
		echo "" ; \
		echo "${PREFIX}/bin/perl" ; \
		echo "${PREFIX}/bin" ; \
		echo "y" ; \
		echo "${PREFIX}/lib/sirc" ; \
		echo "y" ; \
		echo "y" ; \
		echo "n" ; \
		echo "${PREFIX}/man/man1" ; \
		echo "${SERVER}" ; \
		echo "" ; \
	) | ./install


.include <bsd.port.mk>
