# $NetBSD: Makefile,v 1.34 2002/08/31 04:04:36 wiz Exp $

DISTNAME=		esound-0.2.28
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/esound/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		the Enlightened sound daemon

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/esound
CONF_FILES=		${EGDIR}/esd.conf ${PKG_SYSCONFDIR}/esd.conf

.include "../../audio/libaudiofile/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
