# $NetBSD: Makefile,v 1.9 2000/06/01 11:23:42 rh Exp $
#

DISTNAME=	libxml-1.8.7
CATEGORIES=	textproc devel lang gnome
MASTER_SITES=	ftp://rpmfind.net/pub/veillard/ \
		${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://xmlsoft.org/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-*:../../devel/zlib
.endif

USE_PKGLIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
