# $NetBSD: Makefile,v 1.14 2005/03/18 21:08:29 kleink Exp $
#

DISTNAME=	freezetag-0.9.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://katz.linuxpower.org/freezetag/current/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://katz.linuxpower.org/freezetag/
COMMENT=	Id3 tag editor for GTK+-1.2.0 and higher

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
