# $NetBSD: Makefile,v 1.1.1.1 2002/11/03 08:52:25 rh Exp $
#

DISTNAME=		gedit-2.0.5
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gedit/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gedit.sourceforge.net/
COMMENT=		lightweight GNOME2 text editor

BUILD_USES_MSGFMT=	YES

USE_PERL5=		build
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--localstatedir=${SCROLLKEEPER_DATADIR}

.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/eel2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
