# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:19 agc Exp $

DISTNAME=	bison-1.25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	thorpej@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=	yes
MAN1=		bison.1

post-install:
		@install-info ${PREFIX}/info/bison.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
