# $NetBSD: Makefile,v 1.1.1.1 2002/05/04 01:27:08 jtb Exp $

DISTNAME=		zile-1.6.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://zile.sourceforge.net
COMMENT=		Emacs-like text editor

GNU_CONFIGURE=		yes
USE_NCURSES=		yes
USE_BUILDLINK_ONLY= 	yes
INFO_FILES=		zile.info

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
