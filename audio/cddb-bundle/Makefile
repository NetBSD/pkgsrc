# $NetBSD: Makefile,v 1.6 2006/07/22 05:10:54 rillig Exp $
#

DISTNAME=	cddb.bundle-0.2
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	1
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	CDDB client bundle

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/${DISTNAME:C/-[^-]*$//}
NO_CONFIGURE=	yes
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import"

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
