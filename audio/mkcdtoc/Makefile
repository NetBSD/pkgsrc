# $NetBSD: Makefile,v 1.2 2008/07/14 12:55:57 joerg Exp $
#

DISTNAME=		mkcdtoc-1.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mkcdtoc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/mkcdtoc/
COMMENT=		Script to create .toc files for cdrdao

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl
MAKE_ENV+=		PERL=${PERL5}

.include "../../mk/bsd.pkg.mk"
