# $NetBSD: Makefile,v 1.29 2017/07/30 22:32:15 wiz Exp $

DISTNAME=		pcre-ocaml-7.2.3
CATEGORIES=		devel
MASTER_SITES=          ${MASTER_SITE_GITHUB:=mmottl/}
GITHUB_RELEASE=                v${PKGVERSION_NOREV}

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		https://github.com/mmottl/pcre-ocaml
COMMENT=		Perl compatible regular expressions for OCaml
LICENSE=	gnu-lgpl-v2.1

OCAML_USE_OASIS=	yes
USE_TOOLS=	pax
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"
.include "../../mk/ocaml.mk"

EGDIR=			${PREFIX}/share/examples/pcre-ocaml
INSTALLATION_DIRS+=	${EGDIR}
OCAML_FINDLIB_DIRS=	pcre

post-install:
	cd ${WRKSRC}/examples && pax -rw -pm . ${DESTDIR}${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
