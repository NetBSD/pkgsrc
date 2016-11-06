# $NetBSD: Makefile,v 1.15 2016/11/06 19:55:15 wiz Exp $

DISTNAME=		tcllib-1.18
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		Collection of utility modules for Tcl
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
NO_BUILD=		yes

CONFIGURE_ENV+=		ac_cv_path_tclsh=${TCLSH:Q}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,/usr/bin/wget -q -O,${FETCH_CMD:Q} -V -o,g"
SUBST_MESSAGE.fix=	Fixing hardcoded ftp binary.

SUBST_CLASSES+=		tclsh
SUBST_STAGE.tclsh=	post-patch
SUBST_FILES.tclsh=	modules/pki/pki.tcl apps/dtplite apps/nns apps/nnsd\
SUBST_FILES.tclsh+=	apps/nnslog apps/page apps/pt apps/tcldocstrip
SUBST_SED.tclsh=	-e "s,/usr/bin/env.*tclsh,${TCLSH},g"
SUBST_MESSAGE.tclsh=	Fixing path to tclsh.

TEST_TARGET=		test

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
