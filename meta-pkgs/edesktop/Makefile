# $NetBSD: Makefile,v 1.20 2003/05/02 11:55:45 wiz Exp $
#

DISTNAME=	edesktop-1.0
PKGREVISION=	2
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	root@garbled.net
COMMENT=	provides a nearly complete E desktop

DEPENDS+=	enlightenment>=0.16.2:../../wm/enlightenment
DEPENDS+=	eterm-[0-9]*:../../x11/eterm
DEPENDS+=	ethemes-[0-9]*:../../wm/ethemes
DEPENDS+=	rxvt-[0-9]*:../../x11/rxvt
DEPENDS+=	mutt-[0-9]*:../../mail/mutt
DEPENDS+=	econf-[0-9]*:../../wm/econf
DEPENDS+=	xv-[0-9]*:../../graphics/xv
DEPENDS+=	ee-[0-9]*:../../graphics/ee
DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
DEPENDS+=	xpaint-[0-9]*:../../graphics/xpaint
DEPENDS+=	xfig-[0-9]*:../../graphics/xfig
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
DEPENDS+=	jed-[0-9]*:../../editors/jed

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
