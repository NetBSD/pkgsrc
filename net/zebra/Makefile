# New ports collection makefile for:	zebra
# Version required:	0.71
# Date created:		So  31 Mai 1998 11:00:30 CEST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com> (FreeBSD)
#			itojun@itojun.org
#
# $NetBSD: Makefile,v 1.5 1999/07/06 16:31:40 itojun Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	zebra-0.71
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.zebra.org/

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra
# non-IPv6 build at this moment
CONFIGURE_ARGS+=--disable-ospf6d --disable-ripngd

.include "../../mk/bsd.pkg.mk"
