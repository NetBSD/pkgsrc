# $NetBSD: Makefile,v 1.7 2005/01/22 15:42:17 minskim Exp $
#

DISTNAME=	dirdiff-1.6
PKGREVISION=	2
CATEGORIES=	misc tk80
MASTER_SITES=	http://samba.org/ftp/paulus/

DEPENDS=	tk>=8.3.4:../../x11/tk

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/paulus/
COMMENT=	Displays differences between directories

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
