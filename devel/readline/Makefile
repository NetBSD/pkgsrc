# New ports collection makefile for:	readline
# Version required:    			2.1
# Date created:        			Fri Mar  6 19:07:28 GMT 1998
# Whom:                			Alistair Crooks (agc@netbsd.org)
#
# $NetBSD: Makefile,v 1.2 1998/03/10 13:47:35 frueauf Exp $
#

DISTNAME=	readline-2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo

GNU_CONFIGURE=	yes

MAN3=		readline.3

post-install:
	@install-info ${PREFIX}/info/readline.info ${PREFIX}/info/dir

.include <bsd.port.mk>
