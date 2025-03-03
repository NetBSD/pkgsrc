# $NetBSD: Makefile,v 1.3 2025/03/03 01:31:02 scole Exp $

.include "../../devel/tcllib/Makefile.common"

PKGNAME=	${DISTNAME:S/tcllib/tcllibc/}
PKGREVISION=	1
COMMENT=	C-based accelerators for tcllib

USE_TOOLS+=	ls

DEPENDS+=	tcllib>=${PKGVERSION_NOREV}:../../devel/tcllib

PLIST_SUBST+=	PVNR=tcllibc${PKGVERSION_NOREV}

# shared lib for PLIST, xxx use libtool
GENERATE_PLIST+=	(cd ${DESTDIR}${PREFIX} && ${LS} \
			lib/tcllibc*/*/*);

do-build:
	cd ${WRKSRC} && ${TCLSH} sak.tcl critcl \
	-includedir ${DESTDIR}${PREFIX}/include \
	-libdir ${DESTDIR}${PREFIX}/lib \
	-pkg tcllibc${PKGVERSION_NOREV}

do-install:
	# do nothing

.include "../../devel/critcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
