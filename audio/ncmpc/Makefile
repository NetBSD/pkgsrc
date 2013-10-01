# $NetBSD: Makefile,v 1.25 2013/10/01 17:50:57 drochner Exp $

DISTNAME=		ncmpc-0.21
CATEGORIES=		audio
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
MASTER_SITES=		http://www.musicpd.org/download/ncmpc/0/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpd.wikia.com/wiki/Client:Ncmpc
COMMENT=		Curses client for Music Player Daemon
LICENSE=		gnu-gpl-v2

.include "options.mk"

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
