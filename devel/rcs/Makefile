# $NetBSD: Makefile,v 1.6 1999/07/02 08:46:51 agc Exp $
#

DISTNAME=		rcs-5.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=rcs/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/rcs/rcs.html

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

DEPENDS=		diffutils-2.7:../../devel/diffutils

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		PATH=${LOCALBASE}/bin:$PATH

post-install:
	${RM} -f ${PREFIX}/bin/rcslog
	${LN} -s ${PREFIX}/bin/rlog ${PREFIX}/bin/rcslog
	${RM} -f ${PREFIX}/man/man1/rcslog.1 ${PREFIX}/man/man1/rcslog.1.gz
	${LN} -s ${PREFIX}/man/man1/rlog.1 ${PREFIX}/man/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"
