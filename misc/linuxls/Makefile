# $NetBSD: Makefile,v 1.6 1998/08/14 19:57:44 tron Exp $
# FreeBSD Id: Makefile,v 1.6 1997/04/30 04:43:34 asami Exp
#

DISTNAME=	fileutils-3.12
PKGNAME=	linuxls-3.12.0.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

PATCH_SITES=	${MASTER_SITE_SUNSITE}
PATCH_SITE_SUBDIR=	distributions/slackware/source/a/bin/
PATCHFILES=	color-ls-3.12.0.2.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	bmc@WillsCreek.COM

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
