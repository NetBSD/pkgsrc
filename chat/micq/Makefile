# $NetBSD: Makefile,v 1.19.4.1 2005/11/26 07:10:24 salo Exp $

DISTNAME=	micq-0.5.0.4
CATEGORIES=	chat
MASTER_SITES=	http://www.micq.org/source/ \
		ftp://www.micq.org/pub/micq/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.micq.org/
COMMENT=	Text-mode ICQ client

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
