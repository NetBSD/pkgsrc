# $NetBSD: Makefile,v 1.12 2004/04/11 16:21:17 xtraeme Exp $
#

DISTNAME=	freezetag-0.9.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://katz.linuxpower.org/freezetag/current/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://katz.linuxpower.org/freezetag/
COMMENT=	Id3 tag editor for GTK+-1.2.0 and higher

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
