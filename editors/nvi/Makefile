# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:39 tv Exp $
#

DISTNAME=	nvi-1.81.5
PKGREVISION=	1
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
# XXX ignore NetBSD 2.0F and later's granpt(2) and SysV pty for just now
CONFIGURE_ENV+=		vi_cv_sys5_pty=no
.endif

WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix
GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--with-db3=${BUILDLINK_PREFIX.db3}
CONFIGURE_ARGS+=	--program-transform-name='s,^,n,'
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES

.include "../../databases/db3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
