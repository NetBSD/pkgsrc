# $NetBSD: Makefile,v 1.11 2017/09/03 08:53:04 wiz Exp $
#

DISTNAME=		mkcdtoc-1.0
PKGREVISION=		5
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mkcdtoc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/mkcdtoc/
COMMENT=		Script to create .toc files for cdrdao
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake perl pod2man
MAKE_ENV+=		PERL=${PERL5}

.include "../../mk/bsd.pkg.mk"
