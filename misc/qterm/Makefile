# $NetBSD: Makefile,v 1.7 2003/07/21 17:01:26 martti Exp $
#

DISTNAME=	qterm-ac-1.0
PKGNAME=	qterm-1.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.westley.demon.co.uk/software.html
COMMENT=	Utility to recognise terminal type automatically

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/qterm
CONF_FILES=	${EGDIR}/qtermtab ${PKG_SYSCONFDIR}/qtermtab

.include "../../mk/bsd.pkg.mk"
