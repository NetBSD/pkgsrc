# $NetBSD: Makefile,v 1.10 2004/07/19 23:49:35 schmonz Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=	${EZMLM_VERS}

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://cr.yp.to/ezmlm.html
COMMENT=	Easy-to-use, high-speed mailing list manager for qmail

CONFLICTS=	ezmlm-idx-[0-9]*

USE_BUILDLINK3=	yes

# We change conf-bin and conf-man from the default "/usr/local"
# and don't provide compatibility symlinks.
RESTRICTED=	"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-*)
CFLAGS+=	-fno-builtin-log
.endif

.include "../../mk/bsd.pkg.mk"
