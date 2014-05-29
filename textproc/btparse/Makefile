# $NetBSD: Makefile,v 1.19 2014/05/29 23:37:33 wiz Exp $
#

DISTNAME=	btparse-0.35
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AM/AMBS/btparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gerg.ca/software/btOOL/
COMMENT=	BibTeX parsing library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl pod2man
USE_LIBTOOL=YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	btparse.pc.in

.include "../../mk/bsd.pkg.mk"
