# $NetBSD: Makefile,v 1.10 2003/04/10 09:55:51 wiz Exp $

DISTNAME=	micq-0.4.10.2
CATEGORIES=	chat
MASTER_SITES=	http://www.micq.org/source/ \
		ftp://www.micq.org/pub/micq/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://www.micq.org/
COMMENT=	text-mode ICQ client

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
