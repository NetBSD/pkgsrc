# $NetBSD: Makefile,v 1.11 2013/05/31 12:41:30 wiz Exp $
#

DISTNAME=		dirac-1.0.2
PKGREVISION=		3
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dirac.sourceforge.net/
COMMENT=		Open-source video codec designed at the BBC

USE_TOOLS+=		pkg-config perl:run
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	dirac.pc.in

REPLACE_PERL=		tests/create_dirac_testfile.pl

.include "../../mk/bsd.pkg.mk"
