# $NetBSD: Makefile,v 1.2 2002/12/24 06:10:11 wiz Exp $
#

DISTNAME=		gcalctool-4.1.0
PKGREVISION=		1
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/4.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome.org/
COMMENT=		gtk2+ version of calctool

BUILD_USES_MSGFMT=	YES

#USE_PERL5=		build
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
#USE_LIBTOOL=		YES
#LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
