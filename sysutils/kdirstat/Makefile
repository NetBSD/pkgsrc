# $NetBSD: Makefile,v 1.52 2013/02/16 11:24:33 wiz Exp $

DISTNAME=	kdirstat-2.4.4
PKGREVISION=	20
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kdirstat.sourceforge.net/
COMMENT=	Graphical disk usage utility

USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes

REPLACE_PERL=		kdirstat/fix_move_to_trash_bin.pl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
