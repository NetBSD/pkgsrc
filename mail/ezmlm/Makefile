# $NetBSD: Makefile,v 1.13 2004/12/21 04:22:03 schmonz Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=		${EZMLM_VERS}
PKGREVISION=		1

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/ezmlm.html
COMMENT=		Easy-to-use, high-speed mailing list manager for qmail

CONFLICTS=		ezmlm-idx-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

# We change conf-bin and conf-man from the default "/usr/local"
# and don't provide compatibility symlinks.
RESTRICTED=		"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

INSTALLATION_DIRS=	bin man man/man1 man/man5 man/cat1 man/cat5

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-*)
CFLAGS+=		-fno-builtin-log
.endif

.include "../../mk/bsd.pkg.mk"
