# $NetBSD: Makefile,v 1.1.1.1 2001/03/30 00:25:19 hubertf Exp $
#

DISTNAME=	koffice-2.0.1
CATEGORIES=	misc kde

HOMEPAGE=	http://koffice.kde.org/
COMMENT=	KDE Office Suite with text processor, spreadsheet, ...

.include "../../x11/kde2/Makefile.part1"

DEPENDS+=	kdebase-2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=	LIBS="-Wl,-export-dynamic"

.include "../../mk/bsd.pkg.mk"
