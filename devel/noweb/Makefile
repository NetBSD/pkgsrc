# $NetBSD: Makefile,v 1.8 1998/04/24 09:20:34 agc Exp $
# FreeBSD Id: Makefile,v 1.10 1997/09/15 07:22:06 tg Exp
#

DISTNAME=	noweb-2.8a
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.virginia.edu/pub/nr/
EXTRACT_SUFX=	.tgz
ONLY_FOR_ARCHS=	i386

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	icont:../../lang/icon
RUN_DEPENDS=	iconx:../../lang/icon

WRKSRC=		${WRKDIR}/src
MAN1=		cpif.1 nodefs.1 noroots.1 noweb.1 noindex.1 \
		nuweb2noweb.1 notangle.1 sl2h.1 htmltoc.1 \
		nountangle.1 noweave.1
MAN7=		nowebstyle.7 nowebfilters.7

.include "../../mk/bsd.pkg.mk"
