# $NetBSD: Makefile,v 1.14 2008/04/24 21:17:51 markd Exp $
#

DISTNAME=	btparse-0.35
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AM/AMBS/btparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gerg.ca/software/btOOL/
COMMENT=	BibTeX parsing library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl
USE_LIBTOOL=YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	btparse.pc.in

.include "../../mk/bsd.pkg.mk"
