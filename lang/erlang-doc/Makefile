# $NetBSD: Makefile,v 1.3 2008/01/04 14:05:06 ghen Exp $

DISTNAME=		otp_doc_html_${DIST_VERSION_MAJOR}-${DIST_VERSION_MINOR}
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

# these files are already installed by ../../lang/erlang:
DUPLICATE_FILES=	lib/cosEvent-${VERSION.cosEvent:Q}/info
DUPLICATE_FILES+=	lib/cosEventDomain-${VERSION.cosEventDomain:Q}/info
DUPLICATE_FILES+=	lib/mnesia_session-${VERSION.mnesia_session:Q}/info

do-install:
	cd ${WRKDIR} && ${PAX} ${DUPLICATE_FILES:=-s,%,,} -rw doc erts-${VERSION.erts:Q} lib ${PREFIX:Q}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"

.include "../../mk/bsd.pkg.mk"
