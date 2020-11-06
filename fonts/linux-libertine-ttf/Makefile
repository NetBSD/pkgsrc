# $NetBSD: Makefile,v 1.10 2020/11/06 18:04:25 maya Exp $

DISTNAME=	LinLibertineTTF_5.3.0_2012_07_02
PKGNAME=	${DISTNAME:S/LinLibertineTTF_/linux-libertine-ttf-/:C/_[^_].*$//}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linuxlibertine/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxlibertine.sourceforge.net/
COMMENT=	Free TrueType font family
LICENSE=	gnu-gpl-v2 OR ofl-v1.0

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
