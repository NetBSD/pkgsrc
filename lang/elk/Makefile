# $NetBSD: Makefile,v 1.19 2002/01/09 23:12:23 wiz Exp $
# FreeBSD Id: Makefile,v 1.15 1997/09/01 12:28:30 tg Exp
#

DISTNAME=		elk-3.0
PKGNAME=		elk-3.0.3
CATEGORIES=		lang
MASTER_SITES=		http://www-rn.informatik.uni-bremen.de/software/elk/dist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www-rn.informatik.uni-bremen.de/software/elk/
COMMENT=		Embeddable Scheme interpreter

# ELF loading problems, LP64
NOT_FOR_PLATFORM=	*-*-alpha *-*-mips* *-*-sparc64

ALL_TARGET=		default
USE_BUILDLINK_ONLY=	yes

.include "../../mk/bsd.prefs.mk"

# Even with ../../x11/lesstif12 ELK's motif module does not seem to 
# work - it does compile though. So for now Motif support is comment out.
#.if defined(ELK_USE_MOTIF)
#ELK_USE_X11=	# defined
#.endif

do-configure:
	${MV} ${WRKSRC}/src/stab-elf.c ${WRKSRC}/src/stab-elf.c-dist
	${CP} ${FILESDIR}/stab-elf.c ${WRKSRC}/src
	@case `${MAKE} show-shlib-type` in				\
	a.out)	exetype=aout ;;						\
	ELF)	exetype=elf ;;						\
	esac;								\
	${ECHO} "Setting up links for $$exetype on ${LOWER_OPSYS}";	\
	${RM} -f ${WRKSRC}/config/untested/elf-solaris-cc;		\
	${LN} -s ${WRKSRC}/config/sun-sunos5-gcc ${WRKSRC}/config/untested/elf-solaris-cc; \
	${RM} -f ${WRKSRC}/config/system ${WRKSRC}/config/site;		\
	${LN} -s ${WRKSRC}/config/untested/$$exetype-${LOWER_OPSYS}-cc ${WRKSRC}/config/system; \
	for f in aout-netbsd elf-netbsd elf-solaris; do			\
		${RM} -f ${WRKSRC}/config/sites/$$f;			\
		${LN} -s ${WRKSRC}/config/sites/pkgsrc ${WRKSRC}/config/sites/$$f; \
	done;								\
	${LN} -s ${WRKSRC}/config/sites/$$exetype-${LOWER_OPSYS} ${WRKSRC}/config/site

.if defined(ELK_USE_X11)
.  include "../../mk/x11.buildlink.mk"
ELK_SUBDIRS+=	lib/xlib
ELK_SUBDIRS+=	lib/xt
PLIST_SRC+=	${PKGDIR}/PLIST.X11
BUILD_DEFS+=	ELK_USE_X11
X11_LDFLAGS=	-L${X11BASE}/lib
.  if ${_USE_RPATH} == "yes"
X11_LDFLAGS+=-R${X11BASE}/lib
.  endif
MAKE_ENV+=	X11_LDFLAGS="${X11_LDFLAGS}"

.  include "../../mk/xaw.buildlink.mk"
ELK_SUBDIRS+=	lib/xaw
BUILD_DEFS+=	XAW_TYPE
.if ${XAW_TYPE} == "xpm"
EVAL_PREFIX+=	LIBXAW_PREFIX=Xaw-Xpm
.elif ${XAW_TYPE} == "3d"
EVAL_PREFIX+=	LIBXAW_PREFIX=Xaw3d
.endif
.if defined(LIBXAW_PREFIX)
XAW_LDFLAGS+=	-L${LIBXAW_PREFIX}/lib
.  if ${_USE_RPATH} == "yes"
XAW_LDFLAGS+=	-R${LIBXAW_PREFIX}/lib
.  endif
.endif
XAW_LIB=	${LIBXAW:M-l*}
MAKE_ENV+=	XAW_LDFLAGS="${XAW_LDFLAGS}"
MAKE_ENV+=	XAW_LIB="${XAW_LIB}"
.endif

#.if defined(ELK_USE_MOTIF)
#USE_MOTIF12=	# defined
#.  include "../../mk/motif.buildlink.mk"
#ELK_SUBDIRS+=	lib/xm
#ELK_SUBDIRS+=	lib/xm/xt
#PLIST_SRC+=	${PKGDIR}/PLIST.Motif
#BUILD_DEFS+=	ELK_USE_MOTIF
#MOTIF_LDFLAGS=	-L${_MOTIFBASE}/lib
#.  if ${_USE_RPATH} == "yes"
#MOTIF_LDFLAGS+=	-R${_MOTIFBASE}/lib
#.  endif
#MAKE_ENV+=	MOTIF_LDFLAGS="${MOTIF_LDFLAGS}"
#MOTIF_LIB=	${MOTIFLIB:M-l*}
#MAKE_ENV+=	MOTIF_LIB="${MOTIF_LIB}"
#.endif

PLIST_SRC+=	${PKGDIR}/PLIST.base

MAKE_ENV+=	ELK_SUBDIRS="${ELK_SUBDIRS}"

.include "../../mk/bsd.pkg.mk"
