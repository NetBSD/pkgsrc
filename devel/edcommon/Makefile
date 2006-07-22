# $NetBSD: Makefile,v 1.11 2006/07/22 05:10:54 rillig Exp $
#

DISTNAME=	edcommon-32-s
PKGNAME=	${DISTNAME:S/-s$//}
PKGREVISION=	3
CATEGORIES=	devel gnustep
MASTER_SITES=	http://www.mulle-kybernetik.com/software/EDFrameworks/Downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mulle-kybernetik.com/software/EDFrameworks/Downloads/
COMMENT=	Foundation and AppKit extensions

USE_LANGUAGES=	objc

WRKSRC=		${WRKDIR}/ed/EDCommon

MAKE_ENV+=	ADDITIONAL_OBJCFLAGS="-Wno-import -I${WRKSRC}/.."

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

do-configure:
	${LN} -s ${WRKSRC}/*/*.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
