# $NetBSD: Makefile,v 1.22 2010/01/27 21:38:37 joerg Exp $

DISTNAME=	mcrypt-2.6.8
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcrypt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mcrypt.sourceforge.net/
COMMENT=	Replacement to crypt(1), supports many crypto algorithms

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		ac_cv_path_GZIP="gzip"
CONFIGURE_ENV+=		ac_cv_path_BZIP2="bzip2"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
