# $NetBSD: Makefile,v 1.1 2023/06/06 09:56:08 bouyer Exp $

.include "../../cad/ng-spice/Makefile.common"

PKGNAME=	ng-spice-shared-${VERSION}
#PKGREVISION=	1
COMMENT=	Next generation circuit simulation program (shared libraries)

CONFIGURE_ARGS+=	--with-ngshared=YES

post-install:
	${RM} -r ${DESTDIR}${PREFIX}/share/ngspice/scripts


.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
