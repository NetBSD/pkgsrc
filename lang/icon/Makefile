# New ports collection makefile for:    icon
# Version required:     9.3
# Date created:         05 April 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $NetBSD: Makefile,v 1.5 1998/02/01 10:26:26 frueauf Exp $
# FreeBSD Id: Makefile,v 1.8 1997/02/12 08:39:15 tg Exp
#

DISTNAME=       unix
PKGNAME=	icon-9.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.arizona.edu/icon/packages/unix/
ONLY_FOR_ARCHS=	i386

MAINTAINER=	ports@freebsd.org

NO_WRKSUBDIR=	true
ALL_TARGET=	Icon Icon-iconc

OPSYS!=         uname -s
.if (${OPSYS} == "NetBSD")
MANCOMPRESSED=	yes
.endif

MAN1=		icon.1

.include <bsd.port.mk>
