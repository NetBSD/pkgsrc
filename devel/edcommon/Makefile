# $NetBSD: Makefile,v 1.4 2006/01/24 07:32:01 wiz Exp $
#

DISTNAME=		${PKGNAME}-s
PKGNAME=		edcommon-32
PKGREVISION=		1
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
