# $NetBSD: Makefile,v 1.35 2002/09/23 15:02:26 wiz Exp $

DISTNAME=		esound-0.2.29
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.gnome.org/pub/GNOME/sources/esound/0.2/ \
			ftp://gd.tuwien.ac.at/hci/GNOME/gnome.org/sources/esound/0.2/

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
