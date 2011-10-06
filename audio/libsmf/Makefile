# $NetBSD: Makefile,v 1.1.1.1 2011/10/06 11:50:09 ryoon Exp $
#

DISTNAME=	libsmf-1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libsmf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libsmf/
COMMENT=	Standard MIDI File format library
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	smf.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
