# $NetBSD: Makefile,v 1.44 2024/05/29 16:31:18 adam Exp $
#

DISTNAME=	cddb.bundle-0.2
PKGNAME=	${DISTNAME:S/./-/}
PKGREVISION=	30
CATEGORIES=	audio gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gsburn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gsburn.sourceforge.net/
COMMENT=	CDDB client bundle
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/cddb.bundle
NO_CONFIGURE=	yes
USE_LANGUAGES=	objc
MAKE_ENV+=	ADDITIONAL_CPPFLAGS="-Wno-import"
MAKE_FILE=	GNUmakefile

MAKE_FLAGS+=	BUNDLE_INSTALL_DIR=${DESTDIR}${PREFIX}/lib/GNUstep/Bundles

INSTALL_MAKE_FLAGS=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q} \
			INSTALL_DATA=${INSTALL_DATA:Q}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
