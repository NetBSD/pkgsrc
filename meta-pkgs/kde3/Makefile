# $NetBSD: Makefile,v 1.27 2004/04/20 12:08:19 markd Exp $

DISTNAME=	kde-3.2.2
CATEGORIES=	meta-pkgs x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdeaccessibility-3.2.2:../../misc/kdeaccessibility3
DEPENDS+=	kdeartwork-3.2.2:../../misc/kdeartwork3
DEPENDS+=	kdeaddons-3.2.2:../../misc/kdeaddons3
DEPENDS+=	kdeadmin-3.2.2:../../misc/kdeadmin3
DEPENDS+=	kdeedu-3.2.2:../../misc/kdeedu3
DEPENDS+=	kdegames-3.2.2:../../games/kdegames3
DEPENDS+=	kdegraphics-3.2.2:../../graphics/kdegraphics3
DEPENDS+=	kdemultimedia-3.2.2:../../multimedia/kdemultimedia3
DEPENDS+=	kdenetwork-3.2.2:../../net/kdenetwork3
DEPENDS+=	kdepim-3.2.2:../../misc/kdepim3
DEPENDS+=	kdetoys-3.2.2:../../games/kdetoys3
DEPENDS+=	kdeutils-3.2.2:../../misc/kdeutils3
DEPENDS+=	quanta-3.2.2:../../www/quanta3

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
