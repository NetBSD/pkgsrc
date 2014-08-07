# $NetBSD: Makefile,v 1.1 2014/08/07 11:18:04 manu Exp $

VERS=		1.3.8
PKGNAME=	cmockery2-${VERS}
DISTNAME=	v${VERS}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/lpabon/cmockery2/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lpabon/cmockery2/archive/
COMMENT=	Reviving cmockery unit test framework from Google
LICENSE=	apache-2.0

FETCH_USING=	curl

WRKSRC=		${WRKDIR}/cmockery2-${VERS}
AUTOMAKE_REQD=	1.9
USE_TOOLS+=	pkg-config gmake m4 autoconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	cmockery2.pc.in

pre-configure:
	set -e; cd ${WRKSRC} ; sh ./autogen.sh

.include "../../mk/bsd.pkg.mk"
