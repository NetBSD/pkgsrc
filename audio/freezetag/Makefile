# $NetBSD: Makefile,v 1.8 2002/09/21 00:44:25 jlam Exp $
#

DISTNAME=	freezetag-0.9.2
CATEGORIES=	audio
MASTER_SITES=	http://katz.linuxpower.org/freezetag/current/

MAINTAINER=	kleink@netbsd.org
HOMEPAGE=	http://katz.linuxpower.org/freezetag/
COMMENT=	Id3 tag editor for GTK+-1.2.0 and higher

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
