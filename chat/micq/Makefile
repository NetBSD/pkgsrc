# $NetBSD: Makefile,v 1.17 2004/10/03 00:13:15 tv Exp $

DISTNAME=	micq-0.4.10.3
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	http://www.micq.org/source/ \
		ftp://www.micq.org/pub/micq/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.micq.org/
COMMENT=	Text-mode ICQ client

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
