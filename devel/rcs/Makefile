# $NetBSD: Makefile,v 1.12 2003/06/02 01:20:16 jschauma Exp $
#

DISTNAME=		rcs-5.7
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=rcs/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/rcs/rcs.html
COMMENT=		GNU Revision Control System - version control software

ONLY_FOR_PLATFORM=	SunOS-*-* Darwin-*-*	# in NetBSD base system

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS=		diffutils-2.7:../../devel/diffutils
CONFIGURE_ARGS+=	--with-diffutils=gdiff
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		PATH=${LOCALBASE}/bin:$PATH

post-install:
	${RM} -f ${PREFIX}/bin/rcslog
	${LN} -s ${PREFIX}/bin/rlog ${PREFIX}/bin/rcslog
	${RM} -f ${PREFIX}/man/man1/rcslog.1 ${PREFIX}/man/man1/rcslog.1.gz
	${LN} -s ${PREFIX}/man/man1/rlog.1 ${PREFIX}/man/man1/rcslog.1

.include "../../mk/bsd.pkg.mk"
