# $NetBSD: Makefile,v 1.5 2003/06/06 18:26:50 drochner Exp $
#

DISTNAME=		gcalctool-4.2.83
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=calctool/}

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://calctool.sourceforge.net/
COMMENT=		gtk2+ version of calctool

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
USE_PKGLOCALEDIR=	yes

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
