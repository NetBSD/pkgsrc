# $NetBSD: Makefile,v 1.10 2001/02/17 18:09:12 wiz Exp $
# FreeBSD Id: Makefile,v 1.6 1997/04/30 04:43:34 asami Exp
#

DISTNAME=	fileutils-3.12
PKGNAME=	linuxls-3.12.0.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCHFILES=	color-ls-3.12.0.2.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	bmc@WillsCreek.COM
HOMEPAGE=	http://www.gnu.org/software/fileutils/fileutils.html
COMMENT=	FreeBSD port of Linux Slackware colorized GNU `ls'

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
