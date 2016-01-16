# $NetBSD: Makefile,v 1.2 2016/01/16 17:30:31 fhajny Exp $

DISTNAME=	p1_pam-1.0.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/epam/
COMMENT=	Erlang epam for ejabberd to help with PAM authentication
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	epam
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lnsl

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
