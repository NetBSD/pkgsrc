# $NetBSD: Makefile,v 1.20 2000/12/07 14:11:36 is Exp $
#

DISTNAME=	mtools-3.9.5
PKGNAME=	mtools-3.9.5nb1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/

PATCH_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/
PATCHFILES=	mtools-3.9.5-0905.diff.gz

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www.tux.org/pub/knaff/mtools/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
INFO_FILES=	mtools.info

.include "../../mk/bsd.prefs.mk"

.ifdef MTOOLS_ENABLE_FLOPPYD
USE_X11=	yes
CPPFLAGS+=	-I${X11BASE}/include
CONFIGURE_ARGS+=	--enable-floppyd
.endif

PLIST_SRC=	${WRKDIR}/PLIST

pre-patch:
	@${LN} -s . ${WRKSRC}/mtools

post-patch:
	@${RM} ${WRKSRC}/mtools

post-install:
.ifdef MTOOLS_ENABLE_FLOPPYD
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.else
	${RM} -f ${PREFIX}/man/man1/floppyd.1
	${RM} -f ${PREFIX}/bin/floppyd ${PREFIX}/bin/floppyd_installtest
	${GREP} -v /floppyd ${PKGDIR}/PLIST >${PLIST_SRC}
.endif

.include "../../mk/bsd.pkg.mk"
