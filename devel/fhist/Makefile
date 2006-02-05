# $NetBSD: Makefile,v 1.9 2006/02/05 23:08:42 joerg Exp $
#

DISTNAME=		fhist-1.13
PKGREVISION=	2
CATEGORIES=		devel
MASTER_SITES=		http://fhist.sourceforge.net/

MAINTAINER=		Matthew@Aldous.com
HOMEPAGE=		http://fhist.sourceforge.net/
COMMENT=		File history and comparison tools

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES

USE_TOOLS+=		gsoelim

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
