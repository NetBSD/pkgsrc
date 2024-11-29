# $NetBSD: Makefile,v 1.23 2024/11/29 18:46:32 nia Exp $
#

DISTNAME=	hanzim-1.3
PKGREVISION=	11
CATEGORIES=	misc
MASTER_SITES=	http://kamares.ucsd.edu/~arobert/Files/Chinese/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=	http://kamares.ucsd.edu/~arobert/hanzim.html
COMMENT=	Chinese character learning-aid program

WRKSRC=		${WRKDIR}/Hanzim

BUILD_TARGET=	hanzim

# XXX This is presumably needed during installation according to revision
# XXX 1.1 of this Makefile, but needs to be tested.
# XXX
#MAKE_ENV+=	SHELL=${SH:Q} LC_CTYPE=en_US.ISO8859-1

# hanwin.c: In function 'charinfo':
# hanwin.c:481:25: error: array subscript has type 'char' [-Werror=char-subscripts]
#    strcpy(pinyin,init_str[pinyintbl[cht->pinyins.ent[0]].init]);
#                          ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.if empty(DISPLAY)
PKG_FAIL_REASON+=	"requires an Xserver to be running"
.endif

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

CFLAGS+=	-DUSE_INTERP_RESULT

.include "../../mk/bsd.pkg.mk"
