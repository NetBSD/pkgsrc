# $NetBSD: Makefile,v 1.1.1.1 2002/12/18 07:54:44 rh Exp $
#

DISTNAME=		soup-0.7.10
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/soup/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		callback-based mechanism for sending and servicing SOAP requests

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/soup.pc.in

.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
