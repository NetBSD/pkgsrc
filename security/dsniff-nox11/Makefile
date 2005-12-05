# $NetBSD: Makefile,v 1.2 2005/12/05 20:50:55 rillig Exp $

.include "../../security/dsniff/Makefile.common"

PKGNAME=	dsniff-nox11-${VERS}
COMMENT=	Password sniffer

CONFIGURE_ARGS+=	--without-x

post-install:
	${RM} ${PREFIX}/man/man8/webspy.8

.include "../../mk/bsd.pkg.mk"
