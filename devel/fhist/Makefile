# $NetBSD: Makefile,v 1.8 2006/01/15 18:31:50 joerg Exp $
#

DISTNAME=		fhist-1.13
PKGREVISION=	1
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
