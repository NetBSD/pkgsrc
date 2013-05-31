# $NetBSD: Makefile,v 1.6 2013/05/31 12:39:36 wiz Exp $
#

DISTNAME=		mkcdtoc-1.0
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mkcdtoc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/mkcdtoc/
COMMENT=		Script to create .toc files for cdrdao

USE_TOOLS+=		gmake perl pod2man
MAKE_ENV+=		PERL=${PERL5}

.include "../../mk/bsd.pkg.mk"
