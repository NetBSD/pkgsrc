# $NetBSD: Makefile,v 1.24 2003/08/05 21:04:51 skrll Exp $

DISTNAME=	libxslt-1.0.31
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxslt/1.0/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	XSLT parser library from the GNOME project

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libxslt.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--without-python

TEST_TARGET=		check

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
