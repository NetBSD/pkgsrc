# $NetBSD: Makefile,v 1.1 2024/04/02 18:59:15 rhialto Exp $
#

DISTNAME=	oorexx-5.0.0-12583
PKGNAME=	${DISTNAME:C/-[0-9]*$//}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=oorexx/oorexx/${PKGVERSION_NOREV}/}
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=oorexx/oorexx-docs/${PKGVERSION_NOREV}/}
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	ooRexx-${PKGVERSION_NOREV}-pdf.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oorexx.sourceforge.net/
COMMENT=	Powerful typeless object-oriented scripting language
LICENSE=	gnu-gpl-v2 AND cpl-1.0


CONFLICTS=	rexx-imc-[0-9]* rexx-regina-[0-9]*

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	sh:run
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}

# Runs the built executable bin/rexx during build.
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/lib

CMAKE_ARGS+=	-DORX_SHEBANG=${PREFIX}/bin/rexx
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Subversion:BOOL=TRUE

post-install:
	# Fix up bad permissions.
	cd ${DESTDIR}${PREFIX} && \
	    chmod -R go-w . && \
	    chmod a-x lib/rexx.img && \
	    find share/ooRexx/samples/api -name '*.rex' -exec chmod -x {} \; && \
	    find share/ooRexx/samples -name '*.cls' -exec chmod -x {} \;
	# Install pdf documentation.
	cd ${WRKDIR}/ooRexx-${PKGVERSION_NOREV}-pdf && \
	    ${RM} -f oodguide.pdf oodialog.pdf oorexxbuild.pdf oosqlite.pdf \
	          winextensions.pdf
	cd ${WRKDIR} && \
	    ${MV} ooRexx-${PKGVERSION_NOREV}-pdf  ${DESTDIR}${PREFIX}/share/ooRexx/doc


# We really want ncurses!
PREFER.curses=	pkgsrc

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
