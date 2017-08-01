# $NetBSD: Makefile,v 1.15 2017/08/01 16:47:41 wiz Exp $
#

DISTNAME=	qterm-ac-1.0
PKGNAME=	qterm-1.0
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	Utility to recognise terminal type automatically

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/qterm
CONF_FILES=	${EGDIR}/qtermtab ${PKG_SYSCONFDIR}/qtermtab

SUBST_CLASSES+=		qterm
SUBST_STAGE.qterm=	pre-configure
SUBST_FILES.qterm=	aux.c qterm.c qterm.h table.c
SUBST_SED.qterm+=	-e 's|dprintf|qterm_debug_printf|g'

.include "../../mk/bsd.pkg.mk"
