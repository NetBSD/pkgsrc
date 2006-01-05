# $NetBSD: Makefile,v 1.4 2006/01/05 10:08:59 ghen Exp $

DISTNAME=	qbrew-0.3.4
CATEGORIES=	misc
MASTER_SITES=	http://www.usermode.org/code/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.usermode.org/code.html
COMMENT= 	Homebrewer's recipe calculator

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
