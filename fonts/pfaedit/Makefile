# $NetBSD: Makefile,v 1.15 2004/04/24 04:13:36 snj Exp $
#

DISTNAME=	pfaedit_full-${VERSION}
PKGNAME=	pfaedit-20${VERSION}
CATEGORIES=	fonts editors
MASTER_SITES=	http://pfaedit.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pfaedit.sourceforge.net/
COMMENT=	Postscript font editor

VERSION=	040102

CONFIGURE_ARGS+=--with-freetype-src=no
GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
USE_X11=	YES
WRKSRC=		${WRKDIR}/pfaedit-${VERSION}

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
