# $NetBSD: Makefile,v 1.2 2000/03/27 08:54:58 tron Exp $

DISTNAME=		gcc-2.95.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison

BROKEN=			package needs more work, see "Makefile".
# TODO:
# - get "libiberty" to build
# - add files and directores to package list
# - support more platforms

# NetBSD-i386-elf is the only tested platform so far. If you got it
# working on other platforms please add them.
ONLY_FOR_PLATFORM=	NetBSD-1.4[E-Z]-i386 NetBSD-1.[5-9]*-i386

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${SRCDIR}/configure
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld

SRCDIR=			${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/objdir

CONFDIR=		${SRCDIR}/gcc/config
# Files taken from "src/gnu/dist/gcc/config".
CONFFILES=		i386_netbsd-elf.h i386_netbsd.h

post-extract:
	${MKDIR} ${WRKSRC}
	for FILE in ${CONFFILES}; do \
	  case "$$FILE" in \
	  *_* )	${CP} ${FILESDIR}/$$FILE ${CONFDIR}/$${FILE%%_*}/$${FILE#*_} \
		;; \
	  * )	${CP} ${FILESDIR}/$$FILE ${CONFDIR} \
	  	;; \
	  esac; \
	done

.include "../../mk/bsd.pkg.mk"
