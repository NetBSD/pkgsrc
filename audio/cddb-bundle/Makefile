# $NetBSD: Makefile,v 1.2 2006/02/05 23:08:06 joerg Exp $
#

DISTNAME=	cddb.bundle-0.2
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	1
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	CDDB client bundle

WRKSRC=		${WRKDIR}/${DISTNAME:C/-[^-]*$//}
NO_CONFIGURE=	yes
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import"

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
