# $NetBSD: Makefile,v 1.28 2002/02/17 21:55:43 jlam Exp $

DISTNAME=		esound-0.2.23
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/esound/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		the Enlightened sound daemon

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/esound
CONF_FILES=		${EGDIR}/esd.conf ${PKG_SYSCONFDIR}/esd.conf

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
