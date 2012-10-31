# $NetBSD: Makefile,v 1.11 2012/10/31 11:19:49 asau Exp $
#

DISTNAME=		tcllib-1.14
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		Collection of utility modules for Tcl

GNU_CONFIGURE=		yes
NO_BUILD=		yes

CONFIGURE_ENV+=		ac_cv_path_tclsh=${TCLSH:Q}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,/usr/bin/wget -q -O,${FETCH_CMD} -V -o,g"
SUBST_MESSAGE.fix=	Fixing hardcoded ftp binary

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
