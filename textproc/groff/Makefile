# $NetBSD: Makefile,v 1.8 2003/05/15 08:11:01 wiz Exp $
#

DISTNAME=	groff-1.19
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

BUILD_DEPENDS+=	netpbm>=10.0:../../graphics/netpbm

GNU_CONFIGURE=	YES
USE_PERL5=	YES
USE_BUILDLINK2=	YES

INFO_FILES=	groff

.include "../../mk/bsd.prefs.mk"

.ifdef PAPERSIZE
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
