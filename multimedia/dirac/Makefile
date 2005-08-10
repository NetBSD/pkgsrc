# $NetBSD: Makefile,v 1.4 2005/08/10 20:56:20 jlam Exp $
#

DISTNAME=		Dirac-0.2.0
PKGNAME=		${DISTNAME:S/D/d/}
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirac/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://dirac.sourceforge.net/
COMMENT=		Open-source video codec designed at the BBC

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	dirac.pc.in

.include "../../mk/bsd.pkg.mk"
