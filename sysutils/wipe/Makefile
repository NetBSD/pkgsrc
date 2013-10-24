# $NetBSD: Makefile,v 1.7 2013/10/24 09:43:49 jperkin Exp $
#

DISTNAME=		wipe-2.2.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wipe/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wipe.sourceforge.net/
COMMENT=		Secure data destruction
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	DEFINES="-Du_int32_t=uint32_t"
.endif

.include "../../mk/bsd.pkg.mk"
