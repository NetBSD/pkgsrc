# $NetBSD: Makefile,v 1.11 2013/10/18 11:41:18 bsiegert Exp $

DISTNAME=		otp_doc_html_${DIST_VERSION_MAJOR}${DIST_VERSION_MINOR:D-${DIST_VERSION_MINOR}}
PKGNAME=		erlang-doc-${ERLANG_VERSION}
CATEGORIES=		lang
MASTER_SITES=		http://www.erlang.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.erlang.org/
COMMENT=		Documentation for Erlang, a concurrent functional programming language

DIST_SUBDIR=		erlang

# needs erlang installed for its directory structure
DEPENDS+=		erlang-${ERLANG_VERSION}{,nb*}:../../lang/erlang

NO_CONFIGURE=		yes
NO_BUILD=		yes

USE_TOOLS+=		pax

# these files are already installed by ../../lang/erlang:
DUPLICATE_FILES=	lib/cosEvent-${VERSION.cosEvent}/info
DUPLICATE_FILES+=	lib/cosEventDomain-${VERSION.cosEventDomain}/info
DUPLICATE_FILES+=	lib/mnesia_session-${VERSION.mnesia_session}/info

INSTALLATION_DIRS=	lib/erlang

do-install:
	cd ${WRKDIR} && pax ${DUPLICATE_FILES:=-s,%,,} -rw doc erts-${VERSION.erts} lib ${DESTDIR}${PREFIX}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"

.include "../../mk/bsd.pkg.mk"
