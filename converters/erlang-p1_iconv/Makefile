# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:44 fhajny Exp $

DISTNAME=	p1_iconv-0.20150624
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/eiconv/
COMMENT=	Erlang iconv binding
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	eiconv
GITHUB_TAG=	8b7542b1aaf0a851f335e464956956985af6d9a2
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/p1_iconv

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin \
		priv ${DESTDIR}${PREFIX}/lib/erlang/lib/p1_iconv/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
