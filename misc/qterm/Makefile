# $NetBSD: Makefile,v 1.4 2002/12/22 22:26:53 jmmv Exp $
#

DISTNAME=	qterm-ac-1.0
PKGNAME=	qterm-1.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.westley.demon.co.uk/software.html
COMMENT=	utility to recognise terminal type automatically

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/qterm
CONF_FILES=	${EGDIR}/qtermtab ${PKG_SYSCONFDIR}/qtermtab

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
