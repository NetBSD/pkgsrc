# $NetBSD: Makefile,v 1.3 2001/12/12 04:53:40 jmc Exp $

DISTNAME=	libxslt-1.0.7
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

.include "../../textproc/libxml2/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
