# $NetBSD: Makefile,v 1.13 2002/08/31 02:15:29 wiz Exp $
#

DISTNAME=	easytag-0.23
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1&2 TAGs with a GTK+ interface

BUILD_USES_MSGFMT=	yes				# xgettext, really

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes
USE_BUILDLINK2=	yes

.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

MAKE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../mk/bsd.pkg.mk"
