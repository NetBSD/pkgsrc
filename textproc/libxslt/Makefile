# $NetBSD: Makefile,v 1.13 2002/10/29 11:37:40 martti Exp $

DISTNAME=	libxslt-1.0.22
PKGNAME=	${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxslt/1.0/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XSLT parser library for GNOME

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--without-python

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
