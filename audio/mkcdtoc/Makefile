# $NetBSD: Makefile,v 1.14 2020/08/31 18:06:33 wiz Exp $
#

DISTNAME=		mkcdtoc-1.0
PKGREVISION=		8
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
