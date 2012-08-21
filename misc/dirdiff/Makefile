# $NetBSD: Makefile,v 1.15 2012/08/21 23:49:24 marino Exp $
#

DISTNAME=	dirdiff-2.1
PKGREVISION=	1
CATEGORIES=	misc tk
MASTER_SITES=	http://samba.org/ftp/paulus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/paulus/
COMMENT=	Displays differences between directories

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin lib

DEPENDS+=	tk>=8.3.4:../../x11/tk

USE_LIBTOOL=	yes

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
