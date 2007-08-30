# $NetBSD: Makefile,v 1.9 2007/08/30 13:05:45 joerg Exp $
#

DISTNAME=		amsn-0_94
PKGNAME=		${DISTNAME:S/_/./}
PKGREVISION=		3
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=amsn/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.amsn-project.net/
COMMENT=		"Alvaro's MSN messenger client"

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		YES
INSTALLATION_DIRS=	bin

USE_TOOLS+=		perl:run bash:run

REPLACE_INTERPRETER+=	sys-WISH
REPLACE.sys-WISH.old=	.*wish
REPLACE.sys-WISH.new=	${PREFIX}/bin/wish
REPLACE_FILES.sys-WISH=	alarm.tcl blocking.tcl skins.tcl amsn-remote

REPLACE_INTERPRETER+=	sys-TCLSH
REPLACE.sys-TCLSH.old=	.*tclsh
REPLACE.sys-TCLSH.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.sys-TCLSH=amsn-remote-CLI lang/convert.tcl

REPLACE_PERL=		utils/amsnctl.pl lang/complete.pl
REPLACE_BASH=		utils/update-amsn.sh

INSTALLATION_DIRS=	share/amsn share/pixmaps

do-configure:
	@${DO_NADA}

do-install:
	${CP} -R ${WRKSRC}/* ${DESTDIR}${PREFIX}/share/amsn
	${CP} -R ${WRKSRC}/icons/32x32/* ${DESTDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${PREFIX}/share/amsn/amsn ${DESTDIR}${PREFIX}/bin/amsn
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/amsn/amsn

.include "../../security/tcl-tls/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
