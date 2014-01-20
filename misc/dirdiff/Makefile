# $NetBSD: Makefile,v 1.18 2014/01/20 19:20:08 joerg Exp $
#

DISTNAME=	dirdiff-2.1
PKGREVISION=	2
CATEGORIES=	misc tk
MASTER_SITES=	http://samba.org/ftp/paulus/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://samba.org/ftp/paulus/
COMMENT=	Displays differences between directories

INSTALLATION_DIRS+=	bin lib

DEPENDS+=	tk>=8.3.4:../../x11/tk

USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DUSE_INTERP_RESULT

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
