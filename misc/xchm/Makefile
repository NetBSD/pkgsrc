# $NetBSD: Makefile,v 1.7 2004/01/31 23:17:24 xtraeme Exp $
#

DISTNAME=	xchm-0.8.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xchm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xchm.sourceforge.net/
COMMENT=	CHM viewer for UNIX

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

.include "../../devel/chmlib/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
