# $NetBSD: Makefile,v 1.12 2006/03/04 21:30:10 jlam Exp $
#

DISTNAME=	dirdiff-1.6
PKGREVISION=	3
CATEGORIES=	misc tk
MASTER_SITES=	http://samba.org/ftp/paulus/

DEPENDS+=	tk>=8.3.4:../../x11/tk

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/paulus/
COMMENT=	Displays differences between directories

USE_LIBTOOL=	yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
