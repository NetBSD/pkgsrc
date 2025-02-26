# $NetBSD: Makefile,v 1.2 2025/02/26 09:59:00 scole Exp $

.include "../../devel/tcllib/Makefile.common"

PKGNAME=	${DISTNAME:S/tcllib/tcllibc/}
COMMENT=	C-based accelerators for tcllib

USE_TOOLS+=	ls

DEPENDS+=	tcllib>=${PKGVERSION}:../../devel/tcllib

do-install:
	cd ${WRKSRC} && ${TCLSH} sak.tcl critcl \
	-includedir ${DESTDIR}${PREFIX}/include \
	-libdir ${DESTDIR}${PREFIX}/lib \
	-pkg tcllibc${PKGVERSION_NOREV}

# shared lib for PLIST, xxx use libtool
GENERATE_PLIST+=	(cd ${DESTDIR}${PREFIX} && ${LS} \
			lib/tcllibc*/*/*);

.include "../../devel/critcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
