# $NetBSD: Makefile,v 1.13 2004/01/27 00:53:11 heinz Exp $
#

DISTNAME=	fileutils-3.12
PKGNAME=	linuxls-3.12.0.2
PKGREVISION=	2
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

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in -print | \
	while read f; do \
		${CP} $$f $${f}.orig; \
		${SED} -e 's|^\(etcdir = \).*$$|\1${PKG_SYSCONFDIR}|g' $${f}.orig >$$f; \
	done

.include "../../mk/bsd.pkg.mk"
