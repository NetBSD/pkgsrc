# $NetBSD: Makefile,v 1.10 2004/01/20 12:14:06 agc Exp $
#

DISTNAME=	TreeText-0.3.3-src
PKGNAME=	${DISTNAME:C/-src//}
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.ab.wakwak.com/~tino/fox/treetext/
EXTRACT_SUFX=	.zip

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.ab.wakwak.com/~tino/fox/treetext/
COMMENT=	Multi documents editor

BROKEN=		Compilation fails due to outdated code with respect to our fox package.

WRKSRC=		${WRKDIR}/treetext/treetext
USE_BUILDLINK2=	# defined
USE_X11BASE=	# defined

post-extract:
	@${LN} -s ${WRKSRC}/makefile ${WRKSRC}/Makefile
	@${SED} -e 's|$${X11BASE}|${X11BASE}|' ${FILESDIR}/MakeInclude \
		> ${WRKSRC}/MakeInclude

.include "../../x11/fox/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
