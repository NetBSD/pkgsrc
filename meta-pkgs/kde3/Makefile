# $NetBSD: Makefile,v 1.30 2004/10/06 09:25:06 tron Exp $

DISTNAME=	kde-3.3.0
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeaccessibility-3.3.0nb1:../../misc/kdeaccessibility3
DEPENDS+=	kdeartwork-3.3.0nb1:../../misc/kdeartwork3
DEPENDS+=	kdeaddons-3.3.0nb1:../../misc/kdeaddons3
DEPENDS+=	kdeadmin-3.3.0nb1:../../misc/kdeadmin3
DEPENDS+=	kdeedu-3.3.0nb1:../../misc/kdeedu3
DEPENDS+=	kdegames-3.3.0nb1:../../games/kdegames3
DEPENDS+=	kdegraphics-3.3.0nb1:../../graphics/kdegraphics3
DEPENDS+=	kdemultimedia-3.3.0nb1:../../multimedia/kdemultimedia3
DEPENDS+=	kdenetwork-3.3.0nb1:../../net/kdenetwork3
DEPENDS+=	kdepim-3.3.0nb1:../../misc/kdepim3
DEPENDS+=	kdetoys-3.3.0nb1:../../games/kdetoys3
DEPENDS+=	kdeutils-3.3.0nb1:../../misc/kdeutils3
DEPENDS+=	kdewebdev-3.3.0nb1:../../www/kdewebdev3

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
