# New ports collection makefile for:	readline
# Version required:    			2.1
# Date created:        			Fri Mar  6 19:07:28 GMT 1998
# Whom:                			Alistair Crooks (agc@netbsd.org)
#
# $NetBSD: Makefile,v 1.3 1998/03/19 13:02:19 agc Exp $
#

DISTNAME=	readline-2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=    ${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=	yes

MAN3=		readline.3

SCRIPTS_ENV+=	PLIST_SRC="$(PLIST_SRC)"

do-build:
	(cd ${WRKSRC}; make LIB=readline)
	(cd ${WRKSRC}; make LIB=history)

post-install:
	@/sbin/ldconfig || /usr/bin/true

.include <bsd.port.mk>
