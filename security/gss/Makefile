# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:12 tv Exp $
#

DISTNAME=		gss-0.0.15
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/gss/releases/ \
			${MASTER_SITE_GNU:=gss/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gss/
COMMENT=		GNU Generic Security Service Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=    gss.pc.in

INFO_FILES=		gss.info

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
