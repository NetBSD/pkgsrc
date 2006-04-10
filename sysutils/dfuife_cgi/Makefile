# $NetBSD: Makefile,v 1.1.1.1 2006/04/10 15:37:04 joerg Exp $
#

DISTNAME=	dfuife_cgi-1.4
CATEGORIES=	sysutils www
MASTER_SITES=	ftp://packages.stura.uni-rostock.de/bsdinstaller/distfiles/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI CGI frontend

USE_LIBTOOL=	yes
USE_TOOL+=	msgfmt

.include "../../devel/libaura/buildlink3.mk"
.include "../../devel/libdfui/buildlink3.mk"
.include "../../devel/libinstaller/buildlink3.mk"
.include "../../www/cgic/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
