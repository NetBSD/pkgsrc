# $NetBSD: Makefile,v 1.1.1.1 2003/01/04 12:45:42 jmmv Exp $
#

DISTNAME=	file-roller-2.0.4
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fileroller/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://fileroller.sourceforge.net/
COMMENT=	Front-end to archiving programs like tar and zip

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PERL5=		build
USE_PKGLOCALEDIR=	yes

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
