# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:40 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/05/22 07:53:29 tg Exp
#

DISTNAME=	wget-1.4.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=  ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=    ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=	yes
MAN1=		wget.1

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	-install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
