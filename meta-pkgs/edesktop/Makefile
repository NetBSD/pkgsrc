# $NetBSD: Makefile,v 1.10 2000/03/10 16:21:35 minoura Exp $
#

DISTNAME=	edesktop-1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	root@garbled.net

DEPENDS+=	enlightenment-0.16.2:../../x11/enlightenment
DEPENDS+=	eterm-0.8.8:../../x11/eterm
DEPENDS+=	ethemes-*:../../x11/ethemes
DEPENDS+=	rxvt-2.6.1:../../x11/rxvt
DEPENDS+=	mutt-*:../../mail/mutt
DEPENDS+=	econf-0.15:../../x11/econf
DEPENDS+=	xv-3.10apl1:../../graphics/xv
DEPENDS+=	ee-0.3.8:../../graphics/ee
DEPENDS+=	gimp-1.*:../../graphics/gimp
DEPENDS+=	xpaint-2.5.6:../../graphics/xpaint
DEPENDS+=	xfig-3.2.2:../../graphics/xfig
DEPENDS+=	emacs-20.6:../../editors/emacs
DEPENDS+=	jed-0.98-7:../../editors/jed

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
