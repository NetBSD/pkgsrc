# $NetBSD: Makefile,v 1.38 2020/04/12 07:50:24 ryoon Exp $

DISTNAME=	qpdf-10.0.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qpdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qpdf.sourceforge.net/
COMMENT=	Structural, content-preserving transformations on PDF files
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config perl
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libqpdf.pc.in

.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
