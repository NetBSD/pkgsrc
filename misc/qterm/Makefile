# $NetBSD: Makefile,v 1.8 2005/04/30 08:55:00 agc Exp $
#

DISTNAME=	qterm-ac-1.0
PKGNAME=	qterm-1.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	Utility to recognise terminal type automatically

USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/qterm
CONF_FILES=	${EGDIR}/qtermtab ${PKG_SYSCONFDIR}/qtermtab

.include "../../mk/bsd.pkg.mk"
