# $NetBSD: Makefile,v 1.24 2007/06/19 22:37:18 tnn Exp $
#

DISTNAME=		rcs-5.7
PKGREVISION=		3
CATEGORIES=		devel scm
MASTER_SITES=		${MASTER_SITE_GNU:=rcs/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/rcs/rcs.html
COMMENT=		GNU Revision Control System - version control software

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" || ${OPSYS} == "OSF1"
DEPENDS+=		diffutils>=2.7:../../devel/diffutils
CONFIGURE_ARGS+=	--with-diffutils
# the native diff/diff3 is not sufficient for rcs
TOOLS_PLATFORM.diff=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}diff
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PATH=${LOCALBASE}/bin:"$$PATH"
CONFIGURE_HAS_MANDIR=	no

post-install:
	${RM} -f ${PREFIX}/bin/rcslog
	${LN} -s ${PREFIX}/bin/rlog ${PREFIX}/bin/rcslog
	${RM} -f ${PREFIX}/${PKGMANDIR}/man1/rcslog.1 ${PREFIX}/${PKGMANDIR}/man1/rcslog.1.gz
	${LN} -s ${PREFIX}/${PKGMANDIR}/man1/rlog.1 ${PREFIX}/${PKGMANDIR}/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"
