# $NetBSD: Makefile,v 1.9 1998/08/20 15:17:23 tsarna Exp $
# FreeBSD Id: Makefile,v 1.4 1997/05/28 06:18:20 fenner Exp
#

DISTNAME=		9wm-1.1
CATEGORIES=		plan9
MASTER_SITES=		ftp://ftp.mathcs.emory.edu/pub/arnold/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://dhog.g7.org/dhog/9wm.html

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"
