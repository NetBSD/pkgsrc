# $NetBSD: Makefile,v 1.116 2018/11/14 22:22:14 kleink Exp $
#

DISTNAME=		tsclient-0.132
PKGREVISION=		92
CATEGORIES=		net
MASTER_SITES=		http://www.gnomepro.com/tsclient/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnomepro.com/tsclient/
COMMENT=		GNOME2 Frontend for rdesktop

LICENSE=	gnu-gpl-v2

DEPENDS+=	rdesktop-[0-9]*:../../net/rdesktop
DEPENDS+=	vncviewer-[0-9]*:../../net/vncviewer

USE_TOOLS+=		gmake intltool msgfmt perl:run pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
AUTO_MKDIRS=		yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/tsclient.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tsclient.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
