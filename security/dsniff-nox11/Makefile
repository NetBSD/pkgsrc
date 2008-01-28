# $NetBSD: Makefile,v 1.4 2008/01/28 00:45:27 rillig Exp $

.include "../../security/dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
PKGREVISION=	1
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

post-install:
	${RM} ${PREFIX}/${PKGMANDIR}/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
