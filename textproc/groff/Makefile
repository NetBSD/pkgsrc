# $NetBSD: Makefile,v 1.2 2001/08/16 14:43:44 wiz Exp $
#

DISTNAME=	groff-1.16.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

GNU_CONFIGURE=	YES
USE_PERL5=	YES

PLIST_SRC=	${PKGDIR}/PLIST.${LOWER_OPSYS}

.include "../../mk/bsd.prefs.mk"

.ifdef ${PAPERSIZE}
CONFIGURE_ENV+=	PAGE=${PAPERSIZE}
.endif

.include "../../mk/bsd.pkg.mk"
