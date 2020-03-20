# $NetBSD: Makefile,v 1.6 2020/03/20 11:58:17 nia Exp $

DISTNAME=	globalplatform-6.0.0
PKGNAME=	lib${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
# The pkgsrc guide says to do:
# MASTER_SITES=${MASTER_SITE_SOURCEFORGE:=globalplatform/GlobalPlatform%20Library/GlobalPlatform%20Library%20${PKGVERSION_NOREV}/}
# but unfortunately bmake's ":old_string=new_string" variable modifier
# treats the % in the URL as a special character and doesn't provide a
# way to escape it.  So we use the ":@temp@string@" variable modifier
# instead to accomplish the same thing.
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:@.SITE.@${.SITE.}globalplatform/GlobalPlatform%20Library/GlobalPlatform%20Library%20${PKGVERSION_NOREV}/@}

MAINTAINER=	rhansen@bbn.com
HOMEPAGE=	http://globalplatform.sourceforge.net/
COMMENT=	C library for managing GlobalPlatform smart card contents
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
