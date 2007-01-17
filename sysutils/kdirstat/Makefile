# $NetBSD: Makefile,v 1.26 2007/01/17 23:47:23 wiz Exp $

DISTNAME=	kdirstat-2.4.3
PKGREVISION=	4
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kdirstat.sourceforge.net/
COMMENT= 	Graphical disk usage utility

USE_TOOLS+=		gmake msgfmt
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=          yes

REPLACE_PERL=		kdirstat/fix_move_to_trash_bin.pl

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
