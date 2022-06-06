# $NetBSD: Makefile,v 1.31 2022/06/06 05:11:58 dholland Exp $
#

DISTNAME=	tkdesk-2.0
PKGNAME=	${DISTNAME}p2
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://tkdesk.sourceforge.net/dist/

PATCH_SITES=		http://tkdesk.sourceforge.net/patches/
PATCHFILES=		${DISTNAME}p1.patch ${DISTNAME}p2.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tkdesk.sourceforge.net/
COMMENT=	Graphical file manager

USE_TOOLS+=	pax

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib	\
			--with-tk=${BUILDLINK_PREFIX.tk}/lib	\
			--with-itcl=${BUILDLINK_PREFIX.tcl}/lib/itcl${ITCL_VERSION} \
			--with-blt=${BUILDLINK_PREFIX.blt}/lib
MAKE_ENV+=		LIB_RUNTIME_DIR=${BUILDLINK_PREFIX.tcl}/lib/itcl${ITCL_VERSION}

DESTDIR_VARNAME=	INSTALL_ROOT
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

pre-install:
	${RM} -Rf ${WRKSRC}/tcldesk/configs/.trash
	${FIND} ${WRKSRC}/tcldesk -type f \( -name '*.orig' -or -name '*.orig_dist' \) -print | ${XARGS} ${RM} -rf
	${FIND} ${WRKSRC}/tcldesk -type f -print | ${XARGS} ${TOUCH}

.include "../../mk/bsd.pkg.mk"
