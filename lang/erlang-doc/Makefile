# $NetBSD: Makefile,v 1.31 2023/10/23 14:41:05 adam Exp $

DISTNAME=	otp_doc_html_${DIST_VERSION_MAJOR}.${DIST_VERSION_MINOR}
PKGNAME=	${DISTNAME:S/otp_doc_html_/erlang-doc-/}
CATEGORIES=	lang
MASTER_SITES+=	${MASTER_SITE_GITHUB:=erlang/otp/releases/download/OTP-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.erlang.org/
COMMENT=	Documentation for Erlang, a concurrent functional programming language
LICENSE=	apache-2.0

DIST_SUBDIR=	erlang

# needs erlang installed for its directory structure
DEPENDS+=	erlang>=${PKGVERSION_NOREV}:../../lang/erlang

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS=	lib/erlang

do-install:
	cd ${WRKDIR} && pax -rw doc erts-* lib ${DESTDIR}${PREFIX}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"
# overrides


.include "../../mk/bsd.pkg.mk"
