# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:26 tv Exp $
#

DISTNAME=		florist-3.15p-src
PKGNAME=		florist-3.15p
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.nyu.edu/pub/gnat/3.15p/
EXTRACT_SUFX=		.tgz

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.cs.nyu.edu/pub/gnat/3.15p/
COMMENT=		FSU implementation of POSIX.5 (Ada binding)

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_AUTOCONF=		yes
AUTOCONF_REQD=		2.12
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"

# This package requires an Ada compiler. Two are available:
# 1) lang/gcc34-ada and 2) lang/gcc34 built with Ada option
# If USE_GCC_34=YES this package will use gcc34. Otherwise,
# it will use gcc34-ada
BUILD_DEFS=	USE_GCC_34
USE_GCC_34?=	NO

post-extract:
	${CP} ${FILESDIR}/pconfig.NetBSD ${WRKSRC}/configs

pre-configure:
.if !empty(USE_GCC_34:M[Yy][Ee][Ss])
.  include "../../lang/gcc34/preconfigure.mk"
.else
.  include "../../lang/gcc34-ada/preconfigure.mk"
.endif
	cd ${WRKSRC}; ${AUTOCONF}

do-install:
	@${MKDIR} ${PREFIX}/lib/florist
	@${INSTALL_DATA} ${WRKSRC}/floristlib/*.ad[sb] \
		${WRKSRC}/floristlib/*.ali \
		${PREFIX}/lib/florist
	@${INSTALL_DATA} ${WRKSRC}/floristlib/libflorist.a ${PREFIX}/lib

.if !empty(USE_GCC_34:M[Yy][Ee][Ss])
.  include "../../lang/gcc34/buildlink3.mk"
.else
.  include "../../lang/gcc34-ada/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
