# $NetBSD: Makefile,v 1.3 2005/07/21 16:29:53 wiz Exp $
#

DISTNAME=		Dirac-0.2.0
PKGNAME=		${DISTNAME:S/D/d/}
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirac/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://dirac.sourceforge.net/
COMMENT=		Open-source video codec designed at the BBC

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	dirac.pc.in

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
