# $NetBSD: Makefile,v 1.15 2004/01/22 07:49:20 grant Exp $

DISTNAME=	micq-0.4.10.3
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.micq.org/source/ \
		ftp://www.micq.org/pub/micq/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.micq.org/
COMMENT=	Text-mode ICQ client

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
