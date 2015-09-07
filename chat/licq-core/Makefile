# $NetBSD: Makefile,v 1.16 2015/09/07 12:02:07 jperkin Exp $
#

DISTNAME=	licq-1.3.5
PKGNAME=	${DISTNAME:C/-/-core-/}
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=licq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.licq.org/
COMMENT=	ICQ client with plugin support

USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--disable-nls

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-4.[6-9].*)
CFLAGS.SunOS+=		-std=c99 -D_XOPEN_SOURCE=600
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
