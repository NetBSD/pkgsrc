# $NetBSD: Makefile,v 1.12 2002/11/30 23:21:33 salo Exp $
#

DISTNAME=		bonobo-activation-2.1.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/bonobo-activation/2.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		Object activation framework for GNOME2

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc
BUILD_USES_MSGFMT=	YES

USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_PERL5=		build
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/bonobo-activation-2.0.pc.in
GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
