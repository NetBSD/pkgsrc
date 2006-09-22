# $NetBSD: Makefile,v 1.7 2006/09/22 06:33:30 rillig Exp $
#

DISTNAME=	cddb.bundle-0.2
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	1
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	CDDB client bundle

WRKSRC=		${WRKDIR}/cddb.bundle
NO_CONFIGURE=	yes
USE_LANGUAGES=	objc
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import"
MAKE_FILE=	GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
