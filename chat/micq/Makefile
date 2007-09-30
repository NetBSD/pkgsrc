# $NetBSD: Makefile,v 1.26 2007/09/30 17:45:23 wiz Exp $

DISTNAME=	micq-0.5.4
CATEGORIES=	chat
MASTER_SITES=	http://www.micq.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.micq.org/
COMMENT=	Text-mode ICQ client

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
