# $NetBSD: Makefile,v 1.2 2003/07/24 08:42:29 agc Exp $
#

DISTNAME=	dirdiff-1.6
CATEGORIES=	misc tk80
MASTER_SITES=	http://samba.org/ftp/paulus/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/paulus/
COMMENT=	Displays differences between directories

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
