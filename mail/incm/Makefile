# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:00 jlam Exp $
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
.  include "../../pkgtools/libnbcompat/buildlink3.mk" # for utimes()
.endif

.include "../../mk/bsd.pkg.mk"
