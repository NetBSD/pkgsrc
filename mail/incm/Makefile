# $NetBSD: Makefile,v 1.9 2007/09/06 21:51:53 jlam Exp $
#

DISTNAME=	incm-0.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Tool to get mail from mbox file or maildir

CONFLICTS=	mew-[0-9]*

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/incm ${PREFIX}/bin/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
.  include "../../pkgtools/libnbcompat/inplace.mk"	# utimes()
.endif

.include "../../mk/bsd.pkg.mk"
