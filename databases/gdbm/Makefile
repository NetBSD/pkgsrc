# New ports collection makefile for: gdbm
# Version required:	1.7.3
# Date created:		8 Apr 1996
# Whom:			Brent J. Nordquist <bjn@visi.com>
#
# $NetBSD: Makefile,v 1.2 1997/10/27 03:32:44 hubertf Exp $
# FreeBSD Id: Makefile,v 1.4 1997/01/28 08:11:23 asami Exp 
#

DISTNAME=          gdbm-1.7.3
CATEGORIES=        databases
MASTER_SITES=      ${MASTER_SITE_GNU}

MAINTAINER=        bjn@visi.com

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
GNU_CONFIGURE=     yes
MAKE_FLAGS=        CFLAGS="${CFLAGS}" LDFLAGS=-s -f
MAN3=		   gdbm.3

post-build:
	cd ${WRKSRC} ; rm gdbm.info ; make gdbm.info

post-install:
	@install-info ${PREFIX}/info/gdbm.info ${PREFIX}/info/dir

.include <bsd.port.mk>
