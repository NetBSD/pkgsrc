# $NetBSD: Makefile,v 1.44 2023/05/18 14:46:04 schmonz Exp $

DISTNAME=		rcs-5.9.4
PKGREVISION=		1
CATEGORIES=		devel scm
MASTER_SITES=		${MASTER_SITE_GNU:=rcs/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.purdue.edu/homes/trinkle/RCS/
COMMENT=		GNU Revision Control System - version control software
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gsoelim diff:run diff3:run

.if !exists(/bin/ed) && !exists(/usr/bin/ed)
DEPENDS+=		ed-[0-9]*:../../editors/ed
CONFIGURE_ENV+=		ac_cv_path_ED=${PREFIX:Q}/bin/ged
.endif

.include "../../mk/bsd.prefs.mk"

# the native diff/diff3 is not sufficient for rcs
.if ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1" || ${OPSYS} == "AIX" || ${OPSYS} == "Minix"
TOOLS_PLATFORM.diff=
TOOLS_PLATFORM.diff3=
.endif
# DIFF is already in CONFIGURE_ENV
CONFIGURE_ENV+=		DIFF3=${TOOLS_PATH.diff3}

REPLACE_SH=		build-aux/extract-help

INFO_FILES=	yes

# configure will be modified by pkgsrc framework with timestamp update.
# sync timestamp with man/REL to avoid regeneration of man.
post-configure:
	${TOUCH} -r ${WRKSRC}/man/REL ${WRKSRC}/configure

post-install:
	${LN} -s ${DESTDIR}${PREFIX}/bin/rlog ${DESTDIR}${PREFIX}/bin/rcslog
	${LN} -s ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rlog.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"
