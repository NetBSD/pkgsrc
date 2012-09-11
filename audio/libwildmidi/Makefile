# $NetBSD: Makefile,v 1.2 2012/09/12 00:24:45 asau Exp $
#

DISTNAME=	wildmidi-0.2.3.4
PKGNAME=	${DISTNAME:S/wildmidi/libwildmidi/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wildmidi/}

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://wildmidi.sourceforge.net/
COMMENT=	Midi processing library and a midi player using the GUS patch set
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-wildmidi-cfg=${PKG_SYSCONFDIR}/timidity.cfg
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--with-oss

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
