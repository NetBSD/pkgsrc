# $NetBSD: Makefile,v 1.16 2000/08/10 13:37:47 wiz Exp $

DISTNAME=		esound-0.2.19
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/esound/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html

DEPENDS+=		libaudiofile-*:../../audio/libaudiofile

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
