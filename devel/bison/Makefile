# New packages collection makefile for: bison
# Version required:                     1.25
# Date created:                         20 March 1998
# Whom:                                 Jason R. Thorpe
#
# $NetBSD: Makefile,v 1.2 1998/04/13 10:11:28 tron Exp $

DISTNAME=	bison-1.25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	thorpej@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=	yes
MAN1=		bison.1

post-install:
		@install-info ${PREFIX}/info/bison.info ${PREFIX}/info/dir

.include <bsd.port.mk>
