# $NetBSD: Makefile,v 1.21 2008/10/05 22:42:36 smb Exp $
#

DISTNAME=		libetpan-0.56
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://libetpan.sourceforge.net/
COMMENT=		Really nice mail library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c++
USE_LANGUAGES+=		c

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	libetpan-config.in
SUBST_SED.conf=		-e "s|@COMPILERFLAGS@|${COMPILER_RPATH_FLAG}|g"
SUBST_MESSAGE.conf=	Fixing libetpan-config.

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
