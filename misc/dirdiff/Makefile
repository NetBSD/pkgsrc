# $NetBSD: Makefile,v 1.10 2005/12/05 20:50:38 rillig Exp $
#

DISTNAME=	dirdiff-1.6
PKGREVISION=	2
CATEGORIES=	misc tk
MASTER_SITES=	http://samba.org/ftp/paulus/

DEPENDS+=	tk>=8.3.4:../../x11/tk

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/paulus/
COMMENT=	Displays differences between directories

USE_LIBTOOL=	yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
