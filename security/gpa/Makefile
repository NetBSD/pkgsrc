# $NetBSD: Makefile,v 1.80 2026/02/12 08:15:03 wiz Exp $

DISTNAME=	gpa-0.11.0
CATEGORIES=	security x11
MASTER_SITES=	${MASTER_SITE_GNUPG:=gpa/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	https://www.gnupg.org/related_software/gpa/
COMMENT=	GUI frontend to gnupg
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

LIBS.SunOS+=		-lnsl

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
