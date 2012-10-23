# $NetBSD: Makefile,v 1.18 2012/10/23 19:51:27 asau Exp $
#

DISTNAME=	toshutils-991217
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	# http://www.buzzard.me.uk/toshiba/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.buzzard.me.uk/toshiba/
COMMENT=	NetBSD port of the Toshiba(tm) Linux Utilities
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM= *-*-i386

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	YES

USE_TOOLS+=	lex yacc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/toshutils

post-install:
.for f in ac.gif battery.gif hand.gif display.html machine.html modules.html size.html space.html style.html tuxtime.html whatis.html hci.tex sci.tex toshiba.tex
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/doc/toshutils
.endfor

.for p in alarm dispswitch fan hotkey tdocked thotswap tuxtime-conf
SPECIAL_PERMS+=		bin/${p} ${SETUID_ROOT_PERMS}
.endfor

BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
