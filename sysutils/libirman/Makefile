# $NetBSD: Makefile,v 1.1.1.1 2002/05/17 11:32:51 abs Exp $
#

DISTNAME=	libirman-0.4.1b
CATEGORIES=	sysutils
MASTER_SITES=	http://www.evation.com/libirman/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.evation.com/libirman/libirman.html
COMMENT=	Programming library for Irman - infrared control

GNU_CONFIGURE=	YES

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/irman.conf ${PKG_SYSCONFDIR}/irman.conf

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
