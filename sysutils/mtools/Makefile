# $NetBSD: Makefile,v 1.26 2002/02/18 15:14:41 seb Exp $
#

DISTNAME=	mtools-3.9.7
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/knaff/mtools/

MAINTAINER=	is@netbsd.org
HOMEPAGE=	http://www.tux.org/pub/knaff/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools

NOT_FOR_PLATFORM = *-*-alpha *-*-sparc64	# LP64 problem

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INFO_FILES=	mtools.info
TEXINFO_OVERRIDE=	YES

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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
