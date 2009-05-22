# $NetBSD: Makefile,v 1.12 2009/05/22 18:19:03 zafer Exp $
#

DISTNAME=	qterm-ac-1.0
PKGNAME=	qterm-1.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	Utility to recognise terminal type automatically

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=		${PREFIX}/share/examples/qterm
CONF_FILES=	${EGDIR}/qtermtab ${PKG_SYSCONFDIR}/qtermtab

.include "../../mk/bsd.pkg.mk"
