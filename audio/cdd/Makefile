# $NetBSD: Makefile,v 1.7 2001/01/06 06:47:19 simonb Exp $

DISTNAME=	cdd-1.0nb3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	thorpej@netbsd.org

BUILD_DEPENDS+=	${PREFIX}/lib/libscsi.a:../../devel/libscsi

.include "../../mk/bsd.prefs.mk"

.if defined(CDDCPPFLAGS)
MAKE_ENV+=      "CDDCPPFLAGS=${CDDCPPFLAGS}"
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdd ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/stripzeros ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
