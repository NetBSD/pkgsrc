# $NetBSD: Makefile,v 1.15 2014/10/09 19:39:24 jaapb Exp $

DISTNAME=		pcre-ocaml-${VERSION}
PKGNAME=	${DISTNAME} # avoid prefixing with ocaml
VERSION=	7.1.1
CATEGORIES=		devel
MASTER_SITES=		http://github.com/mmottl/pcre-ocaml/releases/download/v${VERSION}/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://github.com/mmottl/pcre-ocaml
COMMENT=		Perl compatible regular expressions for OCaml

OCAML_USE_OASIS=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} != "yes"
BUILD_TARGET=		byte
.endif

EGDIR=			${PREFIX}/share/examples/pcre-ocaml
INSTALLATION_DIRS+=	${EGDIR}

post-install:
	cd ${WRKSRC}/examples && pax -rw -pm . ${DESTDIR}${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
