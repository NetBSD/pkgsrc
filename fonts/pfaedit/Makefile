# $NetBSD: Makefile,v 1.14 2004/02/17 20:41:56 snj Exp $
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
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
USE_X11=	YES
WRKSRC=		${WRKDIR}/pfaedit-${VERSION}

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
