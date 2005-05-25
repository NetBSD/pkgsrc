# $NetBSD: Makefile,v 1.17 2005/05/25 11:50:20 wiz Exp $
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
DEPENDS=		diffutils>=2.7:../../devel/diffutils
CONFIGURE_ARGS+=	--with-diffutils=gdiff
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		PATH=${LOCALBASE}/bin:$$PATH

post-install:
	${RM} -f ${PREFIX}/bin/rcslog
	${LN} -s ${PREFIX}/bin/rlog ${PREFIX}/bin/rcslog
	${RM} -f ${PREFIX}/man/man1/rcslog.1 ${PREFIX}/man/man1/rcslog.1.gz
	${LN} -s ${PREFIX}/man/man1/rlog.1 ${PREFIX}/man/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"
