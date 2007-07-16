# $NetBSD: Makefile,v 1.3 2007/07/16 21:38:39 joerg Exp $
#

DISTNAME=	dfuife_cgi-1.4
CATEGORIES=	sysutils www
MASTER_SITES=	http://www.pkgsrc-box.org/bsdinstaller/distfiles/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.com/
COMMENT=	DFUI CGI frontend

USE_LIBTOOL=	yes
USE_TOOLS+=	msgfmt

.include "../../devel/libaura/buildlink3.mk"
.include "../../devel/libdfui/buildlink3.mk"
.include "../../devel/libinstaller/buildlink3.mk"
.include "../../www/cgic/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
