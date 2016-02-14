# $NetBSD: Makefile,v 1.2 2016/02/14 02:51:19 mef Exp $

VERS=		1.3.8
DISTNAME=	cmockery2-${VERS}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lpabon/}
GITHUB_TAG=	v${VERS}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=lpabon/cmockery2/}
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
