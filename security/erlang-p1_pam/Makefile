# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:45 fhajny Exp $

DISTNAME=	p1_pam-0.20150223
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/epam/
COMMENT=	Erlang epam for ejabberd to help with PAM authentication
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	epam
GITHUB_TAG=	d3ce290b7da75d780a03e86e7a8198a80e9826a6
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes
USE_TOOLS+=	pax

LDFLAGS.SunOS+=	-lnsl

INSTALLATION_DIRS+=	lib/erlang/lib/p1_pam

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/p1_pam/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
