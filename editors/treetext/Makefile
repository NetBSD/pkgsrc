# $NetBSD: Makefile,v 1.5 2003/07/17 21:35:02 grant Exp $
#

DISTNAME=	TreeText-0.3.3-src
PKGNAME=	${DISTNAME:C/-src//}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/treetext/treetext
CATEGORIES=	editors
MASTER_SITES=	http://www.ab.wakwak.com/~tino/fox/treetext/
EXTRACT_SUFX=	.zip

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.ab.wakwak.com/~tino/fox/treetext/
COMMENT=	multi documents editor

USE_BUILDLINK2=	# defined
USE_X11BASE=	# defined

post-extract:
	@${LN} -s ${WRKSRC}/makefile ${WRKSRC}/Makefile
	@${SED} -e 's|$${X11BASE}|${X11BASE}|' ${FILESDIR}/MakeInclude \
		> ${WRKSRC}/MakeInclude

.include "../../x11/fox/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
