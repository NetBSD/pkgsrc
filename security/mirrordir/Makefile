# $NetBSD: Makefile,v 1.2 2003/01/28 22:04:05 jlam Exp $
#

DISTNAME=	mirrordir-0.10.49
CATEGORIES=	security net
MASTER_SITES=	http://mirrordir.sourceforge.net/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mirrordir.sourceforge.net/
COMMENT=	directory mirroring tool

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

EGDIR=		${PREFIX}/share/examples/mirrordir

CONF_FILES=     ${EGDIR}/secure-mcservusers ${PKG_SYSCONFDIR}/secure-mcservusers

.include "../../mk/bsd.pkg.mk"
