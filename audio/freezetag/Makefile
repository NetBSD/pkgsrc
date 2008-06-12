# $NetBSD: Makefile,v 1.19 2008/06/12 02:14:14 joerg Exp $
#

DISTNAME=	freezetag-0.9.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://katz.linuxpower.org/freezetag/current/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://katz.linuxpower.org/freezetag/
COMMENT=	Id3 tag editor for GTK+-1.2.0 and higher

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
