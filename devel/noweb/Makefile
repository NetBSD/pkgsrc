# $NetBSD: Makefile,v 1.14 2000/04/05 14:57:26 pooka Exp $
# FreeBSD Id: Makefile,v 1.10 1997/09/15 07:22:06 tg Exp
#

DISTNAME=		noweb-2.8a
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.cs.virginia.edu/pub/nr/
EXTRACT_SUFX=		.tgz
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-i386

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.virginia.edu/~nr/noweb/

DEPENDS=		icon-9.3.*:../../lang/icon

WRKSRC=			${WRKDIR}/src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS"
do-configure:
	(cd ${WRKSRC} ; ./awkname awk)
.endif

.include "../../mk/bsd.pkg.mk"
