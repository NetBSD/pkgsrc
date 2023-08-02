# $NetBSD: Makefile,v 1.24 2023/08/02 19:21:56 nia Exp $

DISTNAME=		dirac-1.0.2
PKGREVISION=		11
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dirac/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://dirac.sourceforge.net/
COMMENT=		Open-source video codec designed at the BBC

USE_TOOLS+=		perl:run
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

PKGCONFIG_OVERRIDE+=	dirac.pc.in

REPLACE_PERL=		tests/create_dirac_testfile.pl

.include "../../mk/bsd.pkg.mk"
