# New ports collection makefile for:    vic
# Version required:			2.8
# Date created:				1997 Nov 19
# Whom:					is
#
# $NetBSD: Makefile,v 1.3 1998/01/24 20:46:51 hubertf Exp $
# FreeBSD Id: Makefile,v 1.12 1997/09/11 03:54:53 fenner Exp
#

DISTNAME=	vic-2.8
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.8.tar.gz

MAINTAINER=	is@netbsd.org

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		vic.1

post-install:
	strip ${PREFIX}/bin/vic
	strip ${PREFIX}/bin/histtolut

.include <bsd.port.mk>
