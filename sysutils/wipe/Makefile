# $NetBSD: Makefile,v 1.12 2020/03/20 11:58:23 nia Exp $
#

DISTNAME=		wipe-2.3.1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wipe/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wipe.sourceforge.net/
COMMENT=		Secure data destruction
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes

MAKE_ENV.SunOS+=	DEFINES="-Du_int32_t=uint32_t"

.include "../../mk/bsd.pkg.mk"
