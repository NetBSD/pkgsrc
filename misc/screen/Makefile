# New ports collection makefile for:	screen
# Version required:     3.7.2
# Date created:         25 Nov 1994
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.2 1997/10/11 22:14:42 hubertf Exp $
# FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp
#

DISTNAME=       screen-3.7.2
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU}

MAINTAINER=	hubertf@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
GNU_CONFIGURE=	yes
MAN1=		screen.1

post-install:
	@install-info ${PREFIX}/info/screen.info ${PREFIX}/info/dir

.include <bsd.port.mk>
