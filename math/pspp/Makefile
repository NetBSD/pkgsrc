# $NetBSD: Makefile,v 1.30 2004/10/03 00:12:57 tv Exp $
#

DISTNAME=	pspp-0.3.0
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	ftp://franz.stat.wisc.edu/pub/PSPP/ \
		ftp://alpha.gnu.org/gnu/pspp/ \
		ftp://ftp.gwdg.de/pub/gnu-alpha/pspp/ \
		ftp://ftp.unex.es/pub/gnu-beta/pspp/ \
		ftp://ftp.cs.columbia.edu/.archives/gnu/alpha/pspp/ \
		ftp://ftp.kddlabs.co.jp/.1/alpha-gnu/pspp/ \
		ftp://ftp.icm.edu.pl/vol/rzm0/gnu-alpha/pspp/ \
		ftp://ftp.tuniv.szczecin.pl/mirrors/alpha.gnu.org/pub/gnu/pspp/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/pspp/
COMMENT=	Program for statistical analysis of sampled data

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-Dunix=1
CONFIGURE_ARGS=	--sysconfdir="${PKG_SYSCONFDIR}"

INFO_FILES=	pspp.info

PKG_SYSCONFSUBDIR=	pspp
EGDIR=		${PREFIX}/share/examples/pspp
CONF_FILES=	${EGDIR}/devices ${PKG_SYSCONFDIR}/devices
CONF_FILES+=	${EGDIR}/html-prologue ${PKG_SYSCONFDIR}/html-prologue
CONF_FILES+=	${EGDIR}/papersize ${PKG_SYSCONFDIR}/papersize
CONF_FILES+=	${EGDIR}/ps-prologue ${PKG_SYSCONFDIR}/ps-prologue

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
