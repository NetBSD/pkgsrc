# $NetBSD: Makefile,v 1.16 1999/06/02 20:09:02 christos Exp $
#

DISTNAME=	mtools-3.9.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/

PATCH_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/
PATCHFILES=	mtools-3.9.5-0905.diff.gz

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www.tux.org/pub/knaff/mtools/

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${X11BASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

INFO_FILES=	mtools.info

PLIST_SRC=	${WRKDIR}/PLIST

pre-patch:
	@${LN} -s . ${WRKSRC}/mtools

post-patch:
	@${RM} ${WRKSRC}/mtools

post-install:
	@if [ -e ${PREFIX}/bin/floppyd ]; then \
	  ${CP} ${PKGDIR}/PLIST ${PLIST_SRC}; \
	else \
	  ${ECHO} ${RM} -f ${PREFIX}/man/man1/floppyd.1; \
	  ${RM} -f ${PREFIX}/man/man1/floppyd.1; \
	  ${GREP} -v /floppyd ${PKGDIR}/PLIST >${PLIST_SRC}; \
	fi \

.include "../../mk/bsd.pkg.mk"
