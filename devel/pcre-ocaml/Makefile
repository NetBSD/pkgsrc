# $NetBSD: Makefile,v 1.20 2016/02/03 13:02:50 jaapb Exp $

DISTNAME=		pcre-ocaml-7.1.6
PKGNAME=	${DISTNAME} # avoid prefixing with ocaml
CATEGORIES=		devel
MASTER_SITES=          ${MASTER_SITE_GITHUB:=mmottl/}
GITHUB_RELEASE=                v${PKGVERSION_NOREV}

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		http://github.com/mmottl/pcre-ocaml
COMMENT=		Perl compatible regular expressions for OCaml
LICENSE=	gnu-lgpl-v2.1

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
