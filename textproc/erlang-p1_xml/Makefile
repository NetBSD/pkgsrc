# $NetBSD: Makefile,v 1.2 2016/01/13 15:34:15 fhajny Exp $

DISTNAME=	p1_xml-1.1.1
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/xml/
COMMENT=	Fast Expat based Erlang XML parsing library
LICENSE=	apache-2.0

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar
DEPENDS+=	erlang-p1_utils>=1.0.0:../../misc/erlang-p1_utils

GITHUB_PROJECT=	xml
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
