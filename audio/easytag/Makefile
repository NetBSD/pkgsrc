# $NetBSD: Makefile,v 1.12 2002/08/31 02:14:38 wiz Exp $
#

DISTNAME=	easytag-0.23
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1&2 TAGs with a GTK+ interface

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
BUILD_USES_MSGFMT=	yes				# xgettext, really
USE_X11BASE=	yes
USE_BUILDLINK2=	yes

.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

MAKE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../mk/bsd.pkg.mk"
