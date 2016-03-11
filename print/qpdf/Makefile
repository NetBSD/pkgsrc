# $NetBSD: Makefile,v 1.11 2016/03/11 15:37:02 ryoon Exp $

DISTNAME=	qpdf-6.0.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qpdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qpdf.sourceforge.net/
COMMENT=	Structural, content-preserving transformations on PDF files
LICENSE=	artistic-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl:run pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libqpdf.pc.in
REPLACE_PERL=	qpdf/fix-qdf

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
