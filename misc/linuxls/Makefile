# New ports collection makefile for:	Linux-style colorized `ls'
# Version required:			3.12.0.2 (GNU fileutils 3.12)
# Date created:				06 January 1996
# Whom:					bmc@WillsCreek.COM
#
# $NetBSD: Makefile,v 1.2 1997/10/24 01:20:31 hubertf Exp $
# FreeBSD Id: Makefile,v 1.6 1997/04/30 04:43:34 asami Exp
#

DISTNAME=	fileutils-3.12
PKGNAME=	linuxls-3.12.0.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

PATCHFILES=	color-ls-3.12.0.2.patch.gz
PATCH_SITES=	${MASTER_SITE_SUNSITE}
PATCH_SITE_SUBDIR=	distributions/slackware/source/a/bin/

MAINTAINER=	bmc@WillsCreek.COM

PATCH_DIST_STRIP=	-p1
GNU_CONFIGURE=	yes
MAN1=		linuxls.1 dircolors.1

.include <bsd.port.mk>
