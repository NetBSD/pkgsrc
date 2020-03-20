# $NetBSD: Makefile,v 1.19 2020/03/20 11:58:03 nia Exp $
#

DISTNAME=		dirac-1.0.2
PKGREVISION=		8
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dirac.sourceforge.net/
COMMENT=		Open-source video codec designed at the BBC

USE_TOOLS+=		pkg-config perl:run
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++03
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	dirac.pc.in

REPLACE_PERL=		tests/create_dirac_testfile.pl

.include "../../mk/bsd.pkg.mk"
