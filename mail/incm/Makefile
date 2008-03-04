# $NetBSD: Makefile,v 1.11 2008/03/04 17:57:18 jlam Exp $
#

DISTNAME=	incm-0.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Tool to get mail from mbox file or maildir

CONFLICTS=	mew-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_FEATURES=	utimes
GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/incm ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
