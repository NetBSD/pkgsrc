# $NetBSD: Makefile,v 1.3 2007/01/07 09:14:09 rillig Exp $

.include "../../security/dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

post-install:
	${RM} ${PREFIX}/${PKGMANDIR}/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
