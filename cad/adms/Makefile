# $NetBSD: Makefile,v 1.7 2012/09/15 10:03:47 obache Exp $
#

DISTNAME=	adms-2.2.5
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mot-adms/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://mot-adms.sourceforge.net/
COMMENT=	Compact device model code generator for SPICE

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

AUTOMAKE_OVERRIDE=	NO
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake lex pkg-config yacc
USE_LIBTOOL=		YES

CONFIGURE_ENV+=	PKGCONFIG_CONFIG=${PKG_CONFIG:Q}

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
