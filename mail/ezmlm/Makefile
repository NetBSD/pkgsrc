# $NetBSD: Makefile,v 1.9 2004/07/16 00:20:39 schmonz Exp $
#

.include "../../mail/ezmlm/Makefile.common"

DISTNAME=	${EZMLM_VERS}

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://cr.yp.to/ezmlm.html
COMMENT=	Easy-to-use, high-speed mailing list manager for qmail

CONFLICTS=	ezmlm-idx-[0-9]*

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-*)
CFLAGS+=	-fno-builtin-log
.endif

.include "../../mk/bsd.pkg.mk"
