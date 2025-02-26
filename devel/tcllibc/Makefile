# $NetBSD: Makefile,v 1.1 2025/02/26 09:18:10 scole Exp $

.include "../../devel/tcllib/Makefile.common"

PKGNAME=	${DISTNAME:S/tcllib/tcllibc/}
COMMENT=	C-based accelerators for tcllib

DEPENDS+=	tcllib>=${PKGVERSION}:../../devel/tcllib

do-install:
	cd ${WRKSRC} && ${TCLSH} sak.tcl critcl \
	-includedir ${DESTDIR}${PREFIX}/include \
	-libdir ${DESTDIR}${PREFIX}/lib \
	-pkg tcllibc${PKGVERSION_NOREV}

.include "../../devel/critcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
