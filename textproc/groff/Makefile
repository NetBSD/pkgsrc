# $NetBSD: Makefile,v 1.6 2003/02/25 10:17:11 wiz Exp $
#

DISTNAME=	groff-1.18.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

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
