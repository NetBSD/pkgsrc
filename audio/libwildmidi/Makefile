# $NetBSD: Makefile,v 1.1.1.1 2011/11/30 13:47:15 wiz Exp $
#

DISTNAME=	wildmidi-0.2.3.4
PKGNAME=	${DISTNAME:S/wildmidi/libwildmidi/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wildmidi/}

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://wildmidi.sourceforge.net/
COMMENT=	Midi processing library and a midi player using the GUS patch set
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-wildmidi-cfg=${PKG_SYSCONFDIR}/timidity.cfg
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--with-oss

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
