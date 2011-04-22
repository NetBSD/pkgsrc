# $NetBSD: Makefile,v 1.13 2011/04/22 13:43:18 obache Exp $
#

DISTNAME=		florist-3.15p-src
PKGNAME=		florist-3.15p
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.cs.fsu.edu/~baker/ftp/
EXTRACT_SUFX=		.tgz

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.cs.fsu.edu/~baker/florist.html
COMMENT=		FSU implementation of POSIX.5 (Ada binding)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_AUTOCONF=		yes
USE_TOOLS+=		autoconf213 gmake

.include "../../mk/bsd.prefs.mk"

# This package requires an Ada compiler. Two are available:
# 1) lang/gcc34-ada and 2) lang/gcc34 built with Ada option
# If USE_GCC_34=YES this package will use gcc34. Otherwise,
# it will use gcc34-ada
BUILD_DEFS+=	USE_GCC_34
USE_GCC_34?=	NO

post-extract:
	${CP} ${FILESDIR}/pconfig.NetBSD ${WRKSRC}/configs

pre-configure:
.if !empty(USE_GCC_34:M[Yy][Ee][Ss])
.  include "../../lang/gcc34/preconfigure.mk"
.else
.  include "../../lang/gcc34-ada/preconfigure.mk"
.endif
	cd ${WRKSRC}; autoconf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/florist
	${INSTALL_DATA} ${WRKSRC}/floristlib/*.ad[sb] \
		${WRKSRC}/floristlib/*.ali \
		${DESTDIR}${PREFIX}/lib/florist
	${INSTALL_DATA} ${WRKSRC}/floristlib/libflorist.a \
		${DESTDIR}${PREFIX}/lib

.if !empty(USE_GCC_34:M[Yy][Ee][Ss])
.  include "../../lang/gcc34/buildlink3.mk"
.else
.  include "../../lang/gcc34-ada/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
