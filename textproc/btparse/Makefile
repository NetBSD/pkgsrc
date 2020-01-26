# $NetBSD: Makefile,v 1.26 2020/01/26 17:32:13 rillig Exp $
#

DISTNAME=	btparse-0.35
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AM/AMBS/btparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gerg.ca/software/btOOL/
COMMENT=	BibTeX parsing library

USE_TOOLS+=	perl pod2man
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	btparse.pc.in

.include "../../mk/bsd.pkg.mk"
