# $NetBSD: Makefile,v 1.10 2006/07/19 19:14:39 jlam Exp $
#

DISTNAME=	mirrordir-0.10.49
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	http://mirrordir.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mirrordir.sourceforge.net/
COMMENT=	Directory mirroring tool

CONFLICTS=	qmail>=1.03nb7 netqmail>=1.05

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

EGDIR=		${PREFIX}/share/examples/mirrordir

CONF_FILES=     ${EGDIR}/secure-mcservusers ${PKG_SYSCONFDIR}/secure-mcservusers

.include "../../mk/bsd.pkg.mk"
