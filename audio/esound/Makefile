# $NetBSD: Makefile,v 1.15 2000/06/09 07:23:20 jlam Exp $

DISTNAME=		esound-0.2.18
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/esound/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html

DEPENDS+=		libaudiofile-*:../../audio/libaudiofile

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
