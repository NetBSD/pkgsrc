# $NetBSD: Makefile,v 1.23 2004/04/28 05:06:28 snj Exp $
# FreeBSD Id: Makefile,v 1.15 1997/09/01 12:28:30 tg Exp
#

DISTNAME=		elk-3.0
PKGNAME=		elk-3.0.3
CATEGORIES=		lang
MASTER_SITES=		http://www-rn.informatik.uni-bremen.de/software/elk/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-rn.informatik.uni-bremen.de/software/elk/
COMMENT=		Embeddable Scheme interpreter

# ELF loading problems, LP64
NOT_FOR_PLATFORM=	*-*-alpha *-*-mips* *-*-sparc64

ALL_TARGET=		default
USE_BUILDLINK3=		yes

.include "../../mk/bsd.prefs.mk"

ELK_GUI?=	none
BUILD_DEFS+=	ELK_GUI

# We must strip the "-Wl," from the linker flags because they are saved
# by elk to be used to invoke the real "ld", which won't understand them.
#
.if ${ELK_GUI} != "none"
MAKE_ENV+=	X11_LDFLAGS="${X11_LDFLAGS:S/-Wl,//}"
.  if !empty(ELK_GUI:Mxaw)
USE_X11=	# defined
.    include "../../mk/xaw.buildlink3.mk"
LIBXAW:=	${LIBXAW:S/-Wl,//}
ELK_SUBDIRS+=	lib/xlib lib/xt lib/xaw
PLIST_SRC+=	${PKGDIR}/PLIST.X11
BUILD_DEFS+=	XAW_TYPE
.  endif
.  if !empty(ELK_GUI:Mmotif)
.    include "../../mk/motif.buildlink3.mk"
MOTIFLIB:=	${MOTIFLIB:S/-Wl,//}
ELK_SUBDIRS+=	lib/xm lib/xm/xt
PLIST_SRC+=	${PKGDIR}/PLIST.Motif
.  endif
.endif

PLIST_SRC+=	${PKGDIR}/PLIST.base
MAKE_ENV+=	ELK_SUBDIRS="${ELK_SUBDIRS}"

do-configure:
	${MV} ${WRKSRC}/src/stab-elf.c ${WRKSRC}/src/stab-elf.c-dist
	${CP} ${FILESDIR}/stab-elf.c ${WRKSRC}/src
	@case ${OBJECT_FMT} in						\
	a.out)	exetype=aout ;;						\
	ELF)	exetype=elf ;;						\
	*)	${ECHO} "Unsupported object format: ${OBJECT_FMT}";	\
		exit 1 ;;						\
	esac;								\
	${ECHO} "Setting up links for $$exetype on ${LOWER_OPSYS}";	\
	${RM} -f ${WRKSRC}/config/untested/elf-solaris-cc;		\
	${LN} -s ${WRKSRC}/config/sun-sunos5-gcc			\
		${WRKSRC}/config/untested/elf-solaris-cc;		\
	${RM} -f ${WRKSRC}/config/system ${WRKSRC}/config/site;		\
	${LN} -s ${WRKSRC}/config/untested/$$exetype-${LOWER_OPSYS}-cc	\
		${WRKSRC}/config/system;				\
	for f in aout-netbsd elf-netbsd elf-solaris; do			\
		${RM} -f ${WRKSRC}/config/sites/$$f;			\
		${LN} -s ${WRKSRC}/config/sites/pkgsrc			\
			${WRKSRC}/config/sites/$$f;			\
	done;								\
	${LN} -s ${WRKSRC}/config/sites/$$exetype-${LOWER_OPSYS}	\
		${WRKSRC}/config/site

.include "../../mk/bsd.pkg.mk"
