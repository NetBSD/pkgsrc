# $NetBSD: Makefile,v 1.13 2018/01/22 11:22:40 jaapb Exp $

VERSION=	1.6
GITHUB_PROJECT=	optcomp
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/diml/optcomp/
COMMENT=	OCaml syntax extension for optional compilation
LICENSE=	modified-bsd

SUPERSEDES=	optcomp-[0-9]*

OCAML_USE_OASIS=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && oasis setup

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
