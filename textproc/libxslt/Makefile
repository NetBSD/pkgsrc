# $NetBSD: Makefile,v 1.6 2002/05/06 08:10:26 rh Exp $

DISTNAME=	libxslt-1.0.17
PKGNAME=	${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/libxslt/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	Xslt parser library for GNOME

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

BUILDLINK_DEPENDS.libxml2=     libxml2>=2.4.10

.include "../../textproc/libxml2/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
