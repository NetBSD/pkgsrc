# $NetBSD: Makefile,v 1.3 1999/12/16 14:10:14 agc Exp $
# FreeBSD Id: ports/lang/ghc/Makefile,v 1.1.1.1 1999/11/10 17:25:28 nectar Exp

DISTNAME=	ghc-4.04
CATEGORIES=	lang
MASTER_SITES=	http://www.haskell.org/ghc/dist/4.04/
DISTFILES=	ghc-4.04-src.tar.gz ghc-4.04-x86-hc.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.haskell.org/ghc/

DEPENDS+=	readline-4.0:../../devel/readline
DEPENDS+=	gmp-2.0.2:../../devel/gmp

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --enable-hc-boot --libdir=${PREFIX}/lib/ghc
CONFIGURE_ENV+=	HASKELL_OBJ_FMT=`cat ${WRKDIR}/obj_fmt`
WRKSRC=		${WRKDIR}/fptools

# a number of non-i386 platforms, including solaris/sparc, osf/alpha
# etc are supported natively by ghc. pkg support for those platforms
# and their NetBSD varients is left as a mid-level exercise for the reader
ONLY_FOR_PLATFORM= NetBSD-*-i386

# Note:
# 	- This package will bootstrap from pre-compiled C files.
# XXX: we touch the happy-generated files to ensure that when we
# switch to non-bootstrapping mode for installation, the build system
# won't try to create them.
#
pre-configure:
	(	lnl=${WRKDIR}/longandlow; \
		${ECHO} 'int main(){exit(0);}' > $$lnl.c && \
		${CC} $$lnl.c -o $$lnl && \
		file $$lnl | ( ${EGREP} '[^a-zA-Z][Ee][Ll][Ff][^a-zA-Z]' && \
		${ECHO} ELF || ${ECHO} a.out ) \
	) > ${WRKDIR}/obj_fmt
	${SED} < ${WRKSRC}/ghc/driver/ghc.lprl \
	       > ${WRKSRC}/ghc/driver/ghc.lprl.hacked \
		'/push(@SysLibrary, "-l$LibGmp")/s%^%push(@SysLibrary, "-L'${PREFIX}/lib'");%' && \
		${MV} -f ${WRKSRC}/ghc/driver/ghc.lprl.hacked \
			${WRKSRC}/ghc/driver/ghc.lprl
pre-build:
	${CP} ${FILESDIR}/build.mk ${WRKSRC}/mk
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/ghc/compiler/rename/ParseIface.hs
	${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/ghc/compiler/parser/Parser.hs
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} boot)

post-build:
	echo "GhcWithHscBuiltViaC=NO" >>${WRKSRC}/mk/build.mk
	(cd ${WRKSRC}/ghc/lib; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} clean boot all)

.include "../../mk/bsd.pkg.mk"
