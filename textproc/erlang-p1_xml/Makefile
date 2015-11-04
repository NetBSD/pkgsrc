# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:46 fhajny Exp $

DISTNAME=	p1_xml-0.20151023
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/xml/
COMMENT=	Fast Expat based Erlang XML parsing library
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar
DEPENDS+=	erlang-p1_utils-[0-9]*:../../misc/erlang-p1_utils

GITHUB_PROJECT=	xml
GITHUB_TAG=	1c8b016b0ac7986efb823baf1682a43565449e65
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_xml

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_xml/

.include "../../lang/erlang/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
