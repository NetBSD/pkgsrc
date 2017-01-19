# $NetBSD: Makefile,v 1.23 2017/01/19 18:52:23 agc Exp $
#

DISTNAME=		gss-0.0.15
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://josefsson.org/gss/releases/
MASTER_SITES+=		${MASTER_SITE_GNU:=gss/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gss/
COMMENT=		GNU Generic Security Service Library

CONFLICTS+=		heimdal-[0-9]*

USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	gss.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
