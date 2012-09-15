# $NetBSD: Makefile,v 1.23 2012/09/15 10:03:42 obache Exp $

DISTNAME=		ncmpc-0.18
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpd.wikia.com/wiki/Client:Ncmpc
COMMENT=		Curses client for Music Player Daemon
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config msgfmt

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
