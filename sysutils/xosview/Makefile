# New ports collection makefile for:    xosview
# Version required:     		1.5.1
# Date created:         		Fri Oct 24 10:03:55 BST 1997
# Whom:                 		Alistair Crooks (agc@netbsd.org)
#
# $NetBSD: Makefile,v 1.8 1998/03/18 13:42:15 agc Exp $
#

DISTNAME=       xosview-1.5.1
CATEGORIES=	sysutils
MASTER_SITES=   http://www.ece.utexas.edu/~bgrayson/xosview/

MAINTAINER=	bgrayson@ece.utexas.edu

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		xosview.1

MAKE_ENV+=	UVM=${UVM}
MAKE_FLAGS=	ARCH=${ARCH} -f

.include <bsd.port.mk>
