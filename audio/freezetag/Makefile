# $NetBSD: Makefile,v 1.6 2001/12/05 23:32:20 jmc Exp $
#

DISTNAME=	freezetag-0.9.2
CATEGORIES=	audio
MASTER_SITES=	http://katz.linuxpower.org/freezetag/current/

MAINTAINER=	kleink@netbsd.org
HOMEPAGE=	http://katz.linuxpower.org/freezetag/
COMMENT=	Id3 tag editor for GTK+-1.2.0 and higher

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../mk/x11.buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
