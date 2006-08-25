# $NetBSD: Makefile,v 1.6 2006/08/25 10:56:55 minskim Exp $
#

DISTNAME=		tcllib-1.8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		Collection of utility modules for Tcl

GNU_CONFIGURE=		yes
NO_BUILD=		yes
USE_TOOLS+=		tclsh:run

CONFIGURE_ENV+=		ac_cv_path_tclsh=${TCLSH:Q}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,/usr/bin/wget -q -O,${FETCH_CMD} -V -o,g"
SUBST_MESSAGE.fix=	Fixing hardcoded ftp binary

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig | ${XARGS} ${RM}

.include "../../mk/bsd.pkg.mk"
