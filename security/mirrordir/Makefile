# $NetBSD: Makefile,v 1.1.1.1 2001/12/19 14:44:07 agc Exp $
#

DISTNAME=	mirrordir-0.10.49
CATEGORIES=	security net
MASTER_SITES=	http://mirrordir.sourceforge.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mirrordir.sourceforge.net/
COMMENT=	directory mirroring tool

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

EGDIR=		${PREFIX}/share/examples/mirrordir

CONF_FILES=     ${EGDIR}/secure-mcservusers ${PKG_SYSCONFDIR}/secure-mcservusers

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
