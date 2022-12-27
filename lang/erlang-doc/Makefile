# $NetBSD: Makefile,v 1.29 2022/12/27 16:50:43 schmonz Exp $

DISTNAME=		otp_doc_html_${DIST_VERSION_MAJOR}.${DIST_VERSION_MINOR}
PKGNAME=		${DISTNAME:S/otp_doc_html_/erlang-doc-/}
CATEGORIES=		lang
MASTER_SITES=		https://www.erlang.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.erlang.org/
COMMENT=		Documentation for Erlang, a concurrent functional programming language
LICENSE=		apache-2.0

DIST_SUBDIR=		erlang

# needs erlang installed for its directory structure
DEPENDS+=		erlang>=${PKGVERSION_NOREV}:../../lang/erlang

NO_CONFIGURE=		yes
NO_BUILD=		yes

USE_TOOLS+=		pax

INSTALLATION_DIRS=	lib/erlang

do-install:
	cd ${WRKDIR} && pax -rw doc erts-* lib ${DESTDIR}${PREFIX}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"

.include "../../mk/bsd.pkg.mk"
