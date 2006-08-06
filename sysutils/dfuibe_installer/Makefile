# $NetBSD: Makefile,v 1.4 2006/08/06 05:20:40 kristerw Exp $
#

DISTNAME=	dfuibe_installer-1.1.7
CATEGORIES=	sysutils
MASTER_SITES=	ftp://packages.stura.uni-rostock.de/bsdinstaller/distfiles/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI BSD Installer backend

USE_LIBTOOL=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	msgfmt
MAKE_ENV+=	LOCALEDIR=${PREFIX:Q}/${PKGLOCALEDIR:Q}/locale

.include "../../devel/libaura/buildlink3.mk"
.include "../../devel/libdfui/buildlink3.mk"
.include "../../devel/libinstaller/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
