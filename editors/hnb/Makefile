# $NetBSD: Makefile,v 1.1.1.1 2002/11/29 20:17:24 jmmv Exp $
#

DISTNAME=	hnb-1.8.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hnb/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://hnb.sourceforge.net/
COMMENT=	Hierarchical data organizer

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_NCURSES=	yes

.include "../../devel/ncurses/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
