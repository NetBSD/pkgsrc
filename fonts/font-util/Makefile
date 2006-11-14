# $NetBSD: Makefile,v 1.2 2006/11/14 21:11:10 joerg Exp $
#

DISTNAME=		font-util-1.0.1
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Tools for truncating and subseting of ISO10646-1 BDF fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_TOOLS+=		perl:run
REPLACE_PERL+=		bdftruncate.pl

.include "../../mk/bsd.pkg.mk"
