# $NetBSD: Makefile,v 1.11 2002/05/11 18:02:37 wiz Exp $
#

DISTNAME=	fileutils-3.12
PKGNAME=	linuxls-3.12.0.2
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCHFILES=	color-ls-3.12.0.2.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	bmc@WillsCreek.COM
HOMEPAGE=	http://www.gnu.org/software/fileutils/fileutils.html
COMMENT=	Linux Slackware colorized GNU `ls'

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
