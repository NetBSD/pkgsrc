# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:46 fhajny Exp $

DISTNAME=	p1_stringprep-0.20150204
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/stringprep/
COMMENT=	Erlang Stringprep native driver
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	stringprep
GITHUB_TAG=	3c640237a3a7831dc39de6a6d329d3a9af25c579
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_stringprep

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_stringprep/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
