# $NetBSD: Makefile,v 1.3 2001/02/17 09:07:36 agc Exp $
#

DISTNAME=	tclX8.2.0
PKGNAME=	tk-tclX-8.2.0
CATEGORIES=	lang tcl tk
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/TclX/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.neosoft.com/TclX/
COMMENT=	Extended Tcl (TclX), a set of Tcl extensions for system programming

DEPENDS+=	tk-8.3.2:../../x11/tk
DEPENDS+=	tcl-tclX-8.2.0:../../lang/tcl-tclX

CONFLICTS+=	tclX-*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tcl=${PREFIX}/lib \
			--with-tk=${PREFIX}/lib

MAKE_ENV+=		GTAR=${GTAR} CHOWN=${CHOWN} CHMOD=${CHMOD} \
			SHAREMODE=${SHAREMODE} SHAREOWN=${SHAREOWN} \
			SHAREGRP=${SHAREGRP}

WRKSRC=			${WRKDIR}/tclX8.2.0/unix

FILESDIR=	${.CURDIR}/../../lang/tcl-tclX/files
PATCHDIR=	${.CURDIR}/../../lang/tcl-tclX/patches

post-extract:
	${MV} ${WRKSRC}/../doc/Memory.n ${WRKSRC}/../doc/TclXMemory.n

do-build:
	@cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE}

do-install:
	@cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE} install

post-build:
	cd ${WRKSRC}/../tk/unix && ${MAKE_ENV} ${MAKE} buildhelp

post-install:
	${FIND} ${PREFIX}/lib/tcl/tclX8.2/help -type d -exec ${CHMOD} 555 '{}' \;
	${FIND} ${PREFIX}/lib/tcl/tclX8.2/help -type f -exec ${CHMOD} 444 '{}' \;

# 	@${RM} ${PREFIX}/man/man3/TkX_Main.3
# 	@${RM} ${PREFIX}/man/man3/Tkx_Init.3
# the above links are installed based on the contents of the man page.
# we don't want to modify the man page, as it is also used by ../tk-tclX,
# so...

test:
	@(cd ${WRKSRC}/../tk/unix; ${MAKE_ENV} ${MAKE} test)

.include "../../mk/bsd.pkg.mk"
