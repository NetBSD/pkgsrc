# $NetBSD: Makefile,v 1.6 2002/03/13 17:36:49 fredb Exp $
#

DISTNAME=	gtkdiff-1.6.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.ainet.or.jp/~inoue/software/gtkdiff/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.ainet.or.jp/~inoue/software/gtkdiff/index-e.html
COMMENT=	diff front-end program using GNOME

GNU_CONFIGURE=		YES
# At least ORBIT and GNORBA need fixing (orbit-idl and ???)
#USE_BUILDLINK_ONLY=	YES

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
