# $NetBSD: Makefile,v 1.14 2003/07/31 22:02:07 seb Exp $
#

DISTNAME=	groff-1.19
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

DEPENDS+=	netpbm>=10.0:../../graphics/netpbm
DEPENDS+=	psutils>=1.17:../../print/psutils

GNU_CONFIGURE=		YES
USE_GCC_SHLIB=		YES
USE_PERL5=		YES
USE_BUILDLINK2=		YES
USE_NEW_TEXINFO=	YES

INFO_FILES=	groff

post-install:
	${INSTALL_DATA} ${FILESDIR}/mdoc.local \
		${PREFIX}/share/groff/site-tmac

.include "../../mk/bsd.prefs.mk"

.ifdef PAPERSIZE
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
