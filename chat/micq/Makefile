# $NetBSD: Makefile,v 1.25 2007/06/26 09:07:55 rillig Exp $

DISTNAME=	micq-0.5.4
CATEGORIES=	chat
MASTER_SITES=	http://www.micq.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.micq.org/
COMMENT=	Text-mode ICQ client

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
