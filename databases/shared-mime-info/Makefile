# $NetBSD: Makefile,v 1.2 2004/04/05 18:14:42 adam Exp $
#

DISTNAME=	shared-mime-info-0.14
CATEGORIES=	databases
MASTER_SITES=	http://freedesktop.org/Software/shared-mime-info/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/shared-mime-info
COMMENT=	Core database of common types

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CPPFLAGS+=		-DPREFIX=\"\\\"${PREFIX}\\\"\"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
