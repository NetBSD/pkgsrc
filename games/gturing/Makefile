# $NetBSD: Makefile,v 1.12 2003/12/28 23:37:06 jmmv Exp $
#

DISTNAME=		gturing-0.1.1
PKGREVISION=		7
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gturing/0.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 turing machine emulator

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
