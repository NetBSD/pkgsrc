# $NetBSD: Makefile,v 1.2 2002/10/29 12:39:24 wiz Exp $

DISTNAME=		zile-1.6.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zile/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://zile.sourceforge.net
COMMENT=		Emacs-like text editor

GNU_CONFIGURE=		yes
# header include error
USE_NCURSES=		yes
USE_BUILDLINK2= 	yes
INFO_FILES=		zile.info

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
