# $NetBSD: Makefile,v 1.37 2020/06/02 08:23:35 adam Exp $
#

DISTNAME=	edcommon-32-s
PKGNAME=	${DISTNAME:S/-s$//}
PKGREVISION=	25
CATEGORIES=	devel gnustep
MASTER_SITES=	http://www.mulle-kybernetik.com/software/EDFrameworks/Downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mulle-kybernetik.com/software/EDFrameworks/
COMMENT=	Foundation and AppKit extensions
LICENSE=	edcommon-license

PKG_DESTDIR_SUPPORT=	destdir
USE_LANGUAGES=		objc
MAKE_JOBS_SAFE=		no
GNUSTEP_OBSOLETE_ENV=	GNUSTEP_SYSTEM_ROOT

WRKSRC=		${WRKDIR}/ed/EDCommon

MAKE_ENV+=	ADDITIONAL_OBJCFLAGS="-Wno-import -I${WRKSRC}/.."

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gnustep-make/gnustep.mk"

do-configure:
	${LN} -s ${WRKSRC}/*/*.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
