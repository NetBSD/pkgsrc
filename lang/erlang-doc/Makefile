# $NetBSD: Makefile,v 1.33 2024/04/25 08:07:31 adam Exp $

DISTNAME=	otp_doc_html_${DIST_VERSION_MAJOR}.${DIST_VERSION_MINOR}${!empty(DIST_VERSION_PATCH):?.:}${DIST_VERSION_PATCH}
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
	cd ${WRKDIR} && ${PAX} -rw doc erts-* lib ${DESTDIR}${PREFIX}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"
.include "../../mk/bsd.pkg.mk"
