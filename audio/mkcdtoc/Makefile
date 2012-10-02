# $NetBSD: Makefile,v 1.4 2012/10/02 23:47:58 asau Exp $
#

DISTNAME=		mkcdtoc-1.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mkcdtoc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/mkcdtoc/
COMMENT=		Script to create .toc files for cdrdao

USE_TOOLS+=		gmake perl pod2man
MAKE_ENV+=		PERL=${PERL5}

.include "../../mk/bsd.pkg.mk"
