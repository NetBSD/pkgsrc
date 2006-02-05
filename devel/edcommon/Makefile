# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:41 joerg Exp $
#

DISTNAME=		${PKGNAME}-s
PKGNAME=		edcommon-32
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
