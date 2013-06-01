# $NetBSD: Makefile,v 1.33 2013/06/01 14:03:33 ryoon Exp $
#

DISTNAME=		rcs-5.9.0
PKGREVISION=		1
CATEGORIES=		devel scm
MASTER_SITES=		${MASTER_SITE_GNU:=rcs/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.purdue.edu/homes/trinkle/RCS/
COMMENT=		GNU Revision Control System - version control software

USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1" || ${OPSYS} == "AIX" || ${OPSYS} == "Minix"
DEPENDS+=		diffutils>=2.7:../../devel/diffutils
CONFIGURE_ARGS+=	--with-diffutils
# the native diff/diff3 is not sufficient for rcs
TOOLS_PLATFORM.diff=	${LOCALBASE}/bin/gdiff
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PATH=${LOCALBASE}/bin:"$$PATH"

REPLACE_SH=		build-aux/extract-help

post-install:
	${LN} -s ${DESTDIR}${PREFIX}/bin/rlog ${DESTDIR}${PREFIX}/bin/rcslog
	${LN} -s ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rlog.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"
