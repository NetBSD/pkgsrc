# $NetBSD: Makefile,v 1.9 2008/06/21 21:12:05 joerg Exp $
#

DISTNAME=	cddb.bundle-0.2
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	2
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	CDDB client bundle

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/cddb.bundle
NO_CONFIGURE=	yes
USE_LANGUAGES=	objc
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import" \
		GNUSTEP_INSTALLATION_DIR=${PREFIX}/share/GNUstep/Local/
MAKE_FILE=	GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
