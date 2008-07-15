# $NetBSD: Makefile,v 1.10 2008/07/15 16:38:36 joerg Exp $
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

INSTALL_MAKE_FLAGS=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q} \
			INSTALL_DATA=${INSTALL_DATA:Q}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
