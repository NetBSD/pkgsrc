# $NetBSD: Makefile,v 1.12 2009/08/26 19:57:15 sno Exp $
#

DISTNAME=		amsn-0.97
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amsn/}
EXTRACT_SUFX=		.tar.bz2

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
REPLACE_BASH=		utils/update-amsn.sh
USE_TOOLS+=		perl:run bash:run

USE_TOOLS+=		autoconf gmake

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../security/tcl-tls/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
