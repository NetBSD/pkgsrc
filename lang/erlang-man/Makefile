# $NetBSD: Makefile,v 1.7 2012/10/02 20:11:39 asau Exp $

DISTNAME=		otp_doc_man_${DIST_VERSION_MAJOR}${DIST_VERSION_MINOR:D-${DIST_VERSION_MINOR}}
PKGNAME=		erlang-man-${ERLANG_VERSION}
CATEGORIES=		lang
MASTER_SITES=		http://www.erlang.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.erlang.org/
COMMENT=		Documentation for Erlang, a concurrent functional programming language

DIST_SUBDIR=		erlang

# needs erlang installed for its directory structure
DEPENDS+=		erlang-${ERLANG_VERSION}{,nb*}:../../lang/erlang

USE_TOOLS+=		pax

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	cd ${WRKDIR} && pax -rw man ${DESTDIR}${PREFIX}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"

.include "../../mk/bsd.pkg.mk"
