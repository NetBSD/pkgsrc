# $NetBSD: Makefile,v 1.7 2003/09/27 17:07:35 grant Exp $
#

DISTNAME=	hnb-1.8.1
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hnb/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://hnb.sourceforge.net/
COMMENT=	Hierarchical data organizer

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]* NetBSD-1.6[A-U]-*

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

.include "../../mk/curses.buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
