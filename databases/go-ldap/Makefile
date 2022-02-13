# $NetBSD: Makefile,v 1.30 2022/02/13 19:24:27 bsiegert Exp $

DISTNAME=	ldap-3.0.3
PKGNAME=	go-${DISTNAME}
PKGREVISION=	28
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-ldap/}
CATEGORIES=	databases
GITHUB_PROJECT=	ldap
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/go-ldap/ldap
COMMENT=	Basic LDAP v3 functionality for the GO programming language
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	gopkg.in/ldap.v3

.include "../../security/go-asn1-ber/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
