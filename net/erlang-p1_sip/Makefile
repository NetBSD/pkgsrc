# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:45 fhajny Exp $

DISTNAME=	p1_sip-0.20150622
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/p1_esip/
COMMENT=	ProcessOne SIP server component
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar
DEPENDS+=	erlang-p1_stun-[0-9]*:../../net/erlang-p1_stun
DEPENDS+=	erlang-p1_tls-[0-9]*:../../security/erlang-p1_tls
DEPENDS+=	erlang-p1_utils-[0-9]*:../../misc/erlang-p1_utils

GITHUB_PROJECT=	p1_sip
GITHUB_TAG=	d662d3fe7f6288b444ea321d854de0bd6d40e022
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	rebar.config
SUBST_MESSAGE.path=	Fixing include path
SUBST_VARS.path=	LOCALBASE

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	lib/erlang/lib/esip

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/esip/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
