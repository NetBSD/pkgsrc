# $NetBSD: Makefile,v 1.20 2018/04/03 03:06:09 ryoon Exp $

DISTNAME=	qpdf-8.0.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qpdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qpdf.sourceforge.net/
COMMENT=	Structural, content-preserving transformations on PDF files
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libqpdf.pc.in

REPLACE_PERL=	qpdf/fix-qdf

.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
