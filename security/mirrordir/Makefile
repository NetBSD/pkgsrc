# $NetBSD: Makefile,v 1.7 2004/10/03 00:18:10 tv Exp $
#

DISTNAME=	mirrordir-0.10.49
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://mirrordir.sourceforge.net/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mirrordir.sourceforge.net/
COMMENT=	Directory mirroring tool

CONFLICTS=	qmail>=1.03nb7 netqmail>=1.05

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

EGDIR=		${PREFIX}/share/examples/mirrordir

CONF_FILES=     ${EGDIR}/secure-mcservusers ${PKG_SYSCONFDIR}/secure-mcservusers

.include "../../mk/bsd.pkg.mk"
