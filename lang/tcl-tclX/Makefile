# $NetBSD: Makefile,v 1.1.1.1 2000/09/06 16:40:03 jwise Exp $
#

DISTNAME=	tclX8.2.0
PKGNAME=	tcl-tclX-8.2.0
CATEGORIES=	lang tcl
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/TclX/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.neosoft.com/TclX/

DEPENDS+=	tcl-8.3.2:../../lang/tcl

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tcl=${PREFIX}/lib --enable-tk=NO

MAKE_ENV+=		GTAR=${GTAR} CHOWN=${CHOWN} CHMOD=${CHMOD} \
			SHAREMODE=${SHAREMODE} SHAREOWN=${SHAREOWN} \
			SHAREGRP=${SHAREGRP}

WRKSRC=			${WRKDIR}/tclX8.2.0/unix

post-extract:
	${MV} ${WRKSRC}/../doc/Memory.n ${WRKSRC}/../doc/TclXMemory.n

post-build:
	cd ${WRKSRC}/../tcl/unix && ${MAKE_ENV} ${MAKE} buildhelp

post-install:
	${FIND} ${PREFIX}/lib/tcl/tclX8.2/help -type d -exec ${CHMOD} 555 '{}' \;
	${FIND} ${PREFIX}/lib/tcl/tclX8.2/help -type f -exec ${CHMOD} 444 '{}' \;
	@${RM} ${PREFIX}/man/man3/TkX_Main.3
	@${RM} ${PREFIX}/man/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

test:
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} test)

.include "../../mk/bsd.pkg.mk"
