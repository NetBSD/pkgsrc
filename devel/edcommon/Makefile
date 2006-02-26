# $NetBSD: Makefile,v 1.6 2006/02/26 14:40:00 wiz Exp $
#

DISTNAME=		edcommon-32-s
PKGNAME=		${DISTNAME:S/-s$//}
PKGREVISION=		2
CATEGORIES=		devel gnustep
MASTER_SITES=		http://www.mulle-kybernetik.com/software/EDFrameworks/Downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.mulle-kybernetik.com/software/EDFrameworks/Downloads/
COMMENT=		Foundation and AppKit extensions

WRKSRC=			${WRKDIR}/ed/EDCommon

MAKE_ENV+=		ADDITIONAL_OBJCFLAGS="-Wno-import -I${WRKSRC}/.."

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

do-configure:
	${LN} -s ${WRKSRC}/*/*.h ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
