# New ports collection makefile for:    top
# Version required:     3.4
# Date created:         25 Sep 1994
# Whom:                 swallace
#
# FreeBSD Id: Makefile,v 1.14 1997/04/30 23:49:14 asami Exp
#

DISTNAME=       top-3.4
CATEGORIES=	sysutils
MASTER_SITES=   ftp://eecs.nwu.edu/pub/top/

MAINTAINER=	peter@FreeBSD.org

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 221002
BROKEN=		"top is included in FreeBSD version 221002 or later"
.endif

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		freebsd2
MAN1=			top.1

pre-configure:
	${CP} ${FILESDIR}/defaults ${WRKSRC}/.defaults
	${CP} ${FILESDIR}/m_freebsd2.* ${WRKSRC}/machine
	chmod a-x ${WRKSRC}/install

post-install:
	strip ${PREFIX}/bin/top

.include <bsd.port.mk>
