# $NetBSD: Makefile,v 1.1.1.1 2005/03/22 01:05:16 wiz Exp $

.include "../dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

post-install:
	${RM} ${PREFIX}/man/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
