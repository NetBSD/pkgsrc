# $NetBSD: Makefile,v 1.11 2004/02/04 14:01:16 markd Exp $

DISTNAME=	kde-3.2.0
CATEGORIES=	meta-pkgs x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	skrll@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeaccessibility-3.2.0:../../misc/kdeaccessibility3
DEPENDS+=	kdeartwork-3.2.0:../../misc/kdeartwork3
DEPENDS+=	kdeaddons-3.2.0:../../misc/kdeaddons3
DEPENDS+=	kdeadmin-3.2.0:../../misc/kdeadmin3
DEPENDS+=	kdeedu-3.2.0:../../misc/kdeedu3
DEPENDS+=	kdegames-3.2.0:../../games/kdegames3
DEPENDS+=	kdegraphics-3.2.0:../../graphics/kdegraphics3
DEPENDS+=	kdemultimedia-3.2.0:../../multimedia/kdemultimedia3
DEPENDS+=	kdenetwork-3.2.0:../../net/kdenetwork3
DEPENDS+=	kdepim-3.2.0:../../misc/kdepim3
DEPENDS+=	kdetoys-3.2.0:../../games/kdetoys3
DEPENDS+=	kdeutils-3.2.0:../../misc/kdeutils3
DEPENDS+=	quanta-3.2.0:../../www/quanta3

EXTRACT_ONLY=	# empty
USE_BUILDLINK2=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
