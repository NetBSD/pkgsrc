# $NetBSD: Makefile,v 1.10 2004/02/14 17:21:39 jlam Exp $
#

DISTNAME=	nvi-1.81.5
CATEGORIES=	editors
MASTER_SITES=	http://www.kotnet.org/~skimo/nvi/devel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.kotnet.org/~skimo/nvi/devel/
COMMENT=	Berkeley nvi with additional features

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if !empty(OS_VERSION:M[2-9].*) || !empty(OS_VERSION:M1.6[A-Z]*)
CONFIGURE_ENV+=		vi_cv_include_sys_select=no
.  endif
.endif

WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix
GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--with-db3=${BUILDLINK_PREFIX.db3}
CONFIGURE_ARGS+=	--program-transform-name='s,^,n,'
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

.include "../../databases/db3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
