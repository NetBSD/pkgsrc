# $NetBSD: Makefile,v 1.19 2005/12/05 20:50:07 rillig Exp $
#

DISTNAME=		rcs-5.7
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=rcs/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/rcs/rcs.html
COMMENT=		GNU Revision Control System - version control software

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
DEPENDS+=		diffutils>=2.7:../../devel/diffutils
CONFIGURE_ARGS+=	--with-diffutils=gdiff
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PATH=${LOCALBASE}/bin:"$$PATH"
CONFIGURE_HAS_MANDIR=	no

post-install:
	${RM} -f ${PREFIX}/bin/rcslog
	${LN} -s ${PREFIX}/bin/rlog ${PREFIX}/bin/rcslog
	${RM} -f ${PREFIX}/man/man1/rcslog.1 ${PREFIX}/man/man1/rcslog.1.gz
	${LN} -s ${PREFIX}/man/man1/rlog.1 ${PREFIX}/man/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"
