# $NetBSD: Makefile,v 1.2 2002/12/24 06:10:01 wiz Exp $
#

DISTNAME=	pfaedit_full-020910
PKGNAME=	pfaedit-20020910
PKGREVISION=	1
CATEGORIES=	fonts editors
MASTER_SITES=	http://pfaedit.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://pfaedit.sourceforge.net/
COMMENT=	postscript font editor

WRKSRC=		${WRKDIR}/pfaedit
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
