# $NetBSD: Makefile,v 1.9 2015/06/12 10:50:59 wiz Exp $

DISTNAME=	qpdf-5.1.2
PKGREVISION=	1
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
