# $NetBSD: Makefile,v 1.14 2025/09/21 21:22:36 wiz Exp $

DISTNAME=	adms-2.2.5
PKGREVISION=	6
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mot-adms/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mot-adms.sourceforge.net/
COMMENT=	Compact device model code generator for SPICE

AUTOMAKE_OVERRIDE=	NO
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake lex pkg-config yacc
USE_LIBTOOL=		YES

CONFIGURE_ENV+=	PKGCONFIG_CONFIG=${PKG_CONFIG:Q}

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
