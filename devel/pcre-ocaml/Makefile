# $NetBSD: Makefile,v 1.17 2015/01/20 14:31:09 jaapb Exp $

DISTNAME=		pcre-ocaml-${VERSION}
PKGNAME=	${DISTNAME} # avoid prefixing with ocaml
VERSION=	7.1.5
CATEGORIES=		devel
MASTER_SITES=		http://github.com/mmottl/pcre-ocaml/releases/download/v${VERSION}/
LICENSE=	gnu-lgpl-v2.1

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://github.com/mmottl/pcre-ocaml
COMMENT=		Perl compatible regular expressions for OCaml

OCAML_USE_OASIS=	yes
USE_TOOLS=	pax
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"
.include "../../mk/ocaml.mk"

EGDIR=			${PREFIX}/share/examples/pcre-ocaml
INSTALLATION_DIRS+=	${EGDIR}
WRAPPER_DEBUG=	yes

post-install:
	cd ${WRKSRC}/examples && pax -rw -pm . ${DESTDIR}${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
