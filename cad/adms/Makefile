# $NetBSD: Makefile,v 1.18 2026/09/27 11:35:07 tnn Exp $

DISTNAME=	adms-2.2.5
PKGREVISION=	9
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mot-adms/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mot-adms.sourceforge.net/
COMMENT=	Compact device model code generator for SPICE

AUTOMAKE_OVERRIDE=	NO
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake lex pkg-config yacc
USE_LIBTOOL=		YES

CONFIGURE_ENV+=	PKGCONFIG_CONFIG=${PKG_CONFIG:Q}

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
