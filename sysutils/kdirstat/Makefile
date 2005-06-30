# $NetBSD: Makefile,v 1.19 2005/06/30 10:25:33 markd Exp $

DISTNAME=	kdirstat-2.4.3
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kdirstat.sourceforge.net/
COMMENT= 	A graphical disk usage utility

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=          yes
BUILD_USES_MSGFMT=	yes

REPLACE_PERL=		kdirstat/fix_move_to_trash_bin.pl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
