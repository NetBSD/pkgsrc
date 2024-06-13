# $NetBSD: Makefile,v 1.57 2024/06/13 13:47:07 bsiegert Exp $

DISTNAME=	asn1-ber-1.3
PKGNAME=	go-${DISTNAME}
PKGREVISION=	56
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-asn1-ber/}
CATEGORIES=	security
GITHUB_PROJECT=	asn1-ber
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/go-asn1-ber/asn1-ber
COMMENT=	ASN1 BER Encoding/Decoding Library for the GO programming language
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	gopkg.in/asn1-ber.v1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
