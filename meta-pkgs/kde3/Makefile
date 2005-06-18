# $NetBSD: Makefile,v 1.42 2005/06/18 21:24:15 markd Exp $

DISTNAME=	kde-3.4.1
CATEGORIES=	meta-pkgs x11 kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	"meta-package" for the KDE integrated X11 desktop

DEPENDS+=	kdelibs-3.4.1{,nb[0-9]*}:../../misc/kdelibs3
DEPENDS+=	kdeaccessibility-3.4.1{,nb[0-9]*}:../../misc/kdeaccessibility3
DEPENDS+=	kdeartwork-3.4.1{,nb[0-9]*}:../../misc/kdeartwork3
DEPENDS+=	kdeaddons-3.4.1{,nb[0-9]*}:../../misc/kdeaddons3
DEPENDS+=	kdeadmin-3.4.1{,nb[0-9]*}:../../misc/kdeadmin3
DEPENDS+=	kdeedu-3.4.1{,nb[0-9]*}:../../misc/kdeedu3
DEPENDS+=	kdegames-3.4.1{,nb[0-9]*}:../../games/kdegames3
DEPENDS+=	kdegraphics-3.4.1{,nb[0-9]*}:../../graphics/kdegraphics3
DEPENDS+=	kdemultimedia-3.4.1{,nb[0-9]*}:../../multimedia/kdemultimedia3
DEPENDS+=	kdenetwork-3.4.1{,nb[0-9]*}:../../net/kdenetwork3
DEPENDS+=	kdepim-3.4.1{,nb[0-9]*}:../../misc/kdepim3
DEPENDS+=	kdetoys-3.4.1{,nb[0-9]*}:../../games/kdetoys3
DEPENDS+=	kdeutils-3.4.1{,nb[0-9]*}:../../misc/kdeutils3
DEPENDS+=	kdewebdev-3.4.1{,nb[0-9]*}:../../www/kdewebdev3

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
