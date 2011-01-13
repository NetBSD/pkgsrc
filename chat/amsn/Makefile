# $NetBSD: Makefile,v 1.18 2011/01/13 13:37:12 wiz Exp $
#

DISTNAME=		amsn-0.98.3
PKGREVISION=		3
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amsn/}
DISTFILES=		${DISTNAME}-src.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.amsn-project.net/
COMMENT=		Alvaro's MSN messenger client

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
USE_LANGUAGES=		c c++
AUTO_MKDIRS=		yes

REPLACE_INTERPRETER+=	WISH
REPLACE.WISH.old=	.*wish
REPLACE.WISH.new=	${PREFIX}/bin/wish
REPLACE_FILES.WISH=	amsn-remote

REPLACE_INTERPRETER+=	TCLSH
REPLACE.TCLSH.old=	.*tclsh
REPLACE.TCLSH.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.TCLSH=	amsn-remote-CLI lang/convert.tcl

REPLACE_PERL=		utils/amsnctl.pl lang/complete.pl
REPLACE_PERL+=		plugins/music/infogmusicbrowser
REPLACE_BASH=		utils/update-amsn.sh
REPLACE_BASH+=		plugins/music/infoamarok2
REPLACE_BASH+=		plugins/music/infoexaile
REPLACE_BASH+=		plugins/music/infojuk2
REPLACE_BASH+=		plugins/music/infolastfm
REPLACE_BASH+=		plugins/music/infomoc
REPLACE_BASH+=		plugins/music/infompris
REPLACE_BASH+=		plugins/music/inforhythmbox
REPLACE_BASH+=		plugins/music/infospotify
REPLACE_BASH+=		plugins/music/infovlc
USE_TOOLS+=		perl:run bash:run

USE_TOOLS+=		gmake

CHECK_PORTABILITY_SKIP=	utils/macosx/finishbuild.sh

.include "../../security/tcl-tls/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
