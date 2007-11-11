# $NetBSD: Makefile,v 1.38 2007/11/11 23:55:19 wiz Exp $
#

DISTNAME=	pspp-0.3.0
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	ftp://alpha.gnu.org/gnu/pspp/ \
		ftp://ftp.gwdg.de/pub/gnu-alpha/pspp/ \
		ftp://ftp.unex.es/pub/gnu-beta/pspp/ \
		ftp://ftp.cs.columbia.edu/.archives/gnu/alpha/pspp/ \
		ftp://ftp.kddlabs.co.jp/.1/alpha-gnu/pspp/ \
		ftp://ftp.icm.edu.pl/vol/rzm0/gnu-alpha/pspp/ \
		ftp://ftp.tuniv.szczecin.pl/mirrors/alpha.gnu.org/pub/gnu/pspp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/pspp/
COMMENT=	Program for statistical analysis of sampled data

USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
CPPFLAGS+=		-Dunix=1
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR=	pspp
EGDIR=		${PREFIX}/share/examples/pspp
CONF_FILES=	${EGDIR}/devices ${PKG_SYSCONFDIR}/devices
CONF_FILES+=	${EGDIR}/html-prologue ${PKG_SYSCONFDIR}/html-prologue
CONF_FILES+=	${EGDIR}/papersize ${PKG_SYSCONFDIR}/papersize
CONF_FILES+=	${EGDIR}/ps-prologue ${PKG_SYSCONFDIR}/ps-prologue
INFO_FILES=	# PLIST

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
