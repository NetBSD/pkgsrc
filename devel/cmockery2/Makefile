# $NetBSD: Makefile,v 1.6 2022/07/25 11:12:21 wiz Exp $

VERS=		1.3.9
DISTNAME=	cmockery2-${VERS}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lpabon/}
GITHUB_TAG=	v${VERS}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lpabon/cmockery2/
COMMENT=	Reviving cmockery unit test framework from Google
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/cmockery2-${VERS}
AUTOMAKE_REQD=	1.9
USE_TOOLS+=	gmake m4 autoconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	cmockery2.pc.in

pre-configure:
	set -e; cd ${WRKSRC} ; sh ./autogen.sh

.include "../../mk/bsd.pkg.mk"
