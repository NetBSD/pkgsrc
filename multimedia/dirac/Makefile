# $NetBSD: Makefile,v 1.18 2020/01/18 23:33:10 rillig Exp $
#

DISTNAME=		dirac-1.0.2
PKGREVISION=		8
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://dirac.sourceforge.net/
COMMENT=		Open-source video codec designed at the BBC

USE_TOOLS+=		pkg-config perl:run
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++03
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	dirac.pc.in

REPLACE_PERL=		tests/create_dirac_testfile.pl

.include "../../mk/bsd.pkg.mk"
