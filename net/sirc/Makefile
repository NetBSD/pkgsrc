# $NetBSD: Makefile,v 1.1.1.1 1997/11/09 23:39:41 hubertf Exp $

DISTNAME=	sirc-2.141

MASTER_SITES=	http://				# XXX can't remember - HF
MAINTAINER=	hubertf@netbsd.org
CATEGORIES=	net
RUN_DEPENDS=    perl:${PORTSDIR}/lang/perl5

NO_CONFIGURE=	yes
NO_BUILD=	yes

### Enter Default IRC-Server here
SERVER=		us.undernet.org

do-install:
	cd ${WRKSRC} ; ( \
		echo "y" ; \
		echo "" ; \
		echo "" ; \
		echo "${PREFIX}/bin/perl" ; \
		echo "y" ; \
		echo "${PREFIX}/bin" ; \
		echo "y" ; \
		echo "${PREFIX}/lib/sirc" ; \
		echo "y" ; \
		echo "y" ; \
		echo "${SERVER}" ; \
		echo "" ; \
	) | ./install


.include <bsd.port.mk>
