# $NetBSD: Makefile,v 1.34 2018/11/12 16:10:23 jaapb Exp $

VERSION=		7.3.4
DISTNAME=		pcre-${VERSION}
PKGNAME=		pcre-ocaml-${VERSION}
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=          ${MASTER_SITE_GITHUB:=mmottl/}

MAINTAINER=		jaapb@NetBSD.org
HOMEPAGE=		https://github.com/mmottl/pcre-ocaml
COMMENT=		Perl compatible regular expressions for OCaml
LICENSE=	gnu-lgpl-v2.1

WRKSRC=	${WRKDIR}/pcre-ocaml-${VERSION}

OCAML_USE_JBUILDER=	yes
OPAM_INSTALL_FILES=	pcre
USE_TOOLS=	pax

.include "../../mk/bsd.prefs.mk"
.include "../../mk/ocaml.mk"

EGDIR=			${PREFIX}/share/examples/pcre-ocaml
INSTALLATION_DIRS+=	${EGDIR}
OCAML_FINDLIB_DIRS=	pcre

post-install:
	cd ${WRKSRC}/examples && pax -rw -pm . ${DESTDIR}${EGDIR}

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-configurator/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
