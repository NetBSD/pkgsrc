# $NetBSD: Makefile,v 1.8 2018/03/12 11:15:59 wiz Exp $

DISTNAME=	asunder-2.5
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://littlesvr.ca/asunder/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dtyson@anduin.org.uk
HOMEPAGE=	http://littlesvr.ca/asunder/
COMMENT=	Graphical CD ripper
LICENSE=	gnu-gpl-v2

DEPENDS+=	cdparanoia-[0-9]*:../../audio/cdparanoia
DEPENDS+=	lame-[0-9]*:../../audio/lame
DEPENDS+=	flac-[0-9]*:../../audio/flac

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt

BUILDLINK_API_DEPENDS.libcddb+=	libcddb>=0.9.5
.include "../../audio/libcddb/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
