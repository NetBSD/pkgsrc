# $NetBSD: Makefile,v 1.10 2003/05/25 07:20:05 jmc Exp $
#

DISTNAME=	groff-1.19
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

DEPENDS+=	netpbm>=10.0:../../graphics/netpbm
DEPENDS+=	psutils>=1.17:../../print/psutils

GNU_CONFIGURE=	YES
USE_PERL5=	YES
USE_BUILDLINK2=	YES

INFO_FILES=	groff

.include "../../mk/bsd.prefs.mk"

.ifdef PAPERSIZE
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

.include "../../mk/ghostscript.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
