# $NetBSD: Makefile,v 1.6 1998/04/15 10:38:44 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/05/28 06:18:20 fenner Exp
#

DISTNAME=		9wm-1.1
CATEGORIES=		plan9
MASTER_SITES=		ftp://ftp.mathcs.emory.edu/pub/arnold/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		erich@FreeBSD.org

NO_WRKSUBDIR=		yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
USE_IMAKE=		yes

CAT1=			9wm.0

.include "../../mk/bsd.pkg.mk"
