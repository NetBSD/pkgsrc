# $NetBSD: Makefile,v 1.12 2000/10/17 23:58:17 jlam Exp $
#

DISTNAME=		libxml-1.8.10
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		ftp://rpmfind.net/pub/veillard/ \
			${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://xmlsoft.org/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=		zlib-*:../../devel/zlib
.endif

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
