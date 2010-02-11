# $NetBSD: Makefile,v 1.14 2010/02/11 19:07:56 joerg Exp $
#

DISTNAME=	dirdiff-2.1
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
