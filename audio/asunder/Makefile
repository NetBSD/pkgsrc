# $NetBSD: Makefile,v 1.18 2020/11/01 16:03:39 triaxx Exp $

DISTNAME=	asunder-2.9.6
CATEGORIES=	audio
MASTER_SITES=	http://littlesvr.ca/asunder/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dtyson@anduin.org.uk
HOMEPAGE=	http://littlesvr.ca/asunder/
COMMENT=	Graphical CD ripper
LICENSE=	gnu-gpl-v2

DEPENDS+=	cdparanoia-[0-9]*:../../audio/cdparanoia

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		intltool msgfmt msgmerge xgettext

.include "options.mk"

BUILDLINK_API_DEPENDS.libcddb+=	libcddb>=0.9.5
.include "../../audio/libcddb/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
