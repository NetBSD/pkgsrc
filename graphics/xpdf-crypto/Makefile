# $NetBSD: Makefile,v 1.4 2000/08/18 22:46:36 hubertf Exp $
# FreeBSD Id: Makefile,v 1.12 1998/03/11 03:08:12 vanilla Exp
# 

PKGNAME=	xpdf-crypto-${VERS}

PATCH_SITES=	http://www.fefe.de/
PATCHFILES=	xpdf-0.90-fefe-diff2.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=     packages@netbsd.org
HOMEPAGE=       http://www.foolabs.com/xpdf/

RESTRICTED=	"Crypto; export-controlled"
NO_SRC_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

CONFLICTS=	xpdf-0.[789][a0]

.include "../xpdf/Makefile.common"
