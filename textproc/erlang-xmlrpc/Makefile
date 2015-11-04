# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:46 fhajny Exp $

DISTNAME=	xmlrpc-1.15.20150506
PKGNAME=	erlang-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rds13/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/rds13/xmlrpc/
COMMENT=	Erlang XMLRPC implementation with SSL, cookies, Authentication
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	xmlrpc
GITHUB_TAG=	42e6e96a0fe7106830274feed915125feb1056f3
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pax

INSTALLATION_DIRS+=	lib/erlang/lib/xmlrpc

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin include \
		${DESTDIR}${PREFIX}/lib/erlang/lib/xmlrpc/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
