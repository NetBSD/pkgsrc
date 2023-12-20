# $NetBSD: Makefile,v 1.14 2023/12/20 18:46:53 wiz Exp $

DISTNAME=	otp_doc_man_${DIST_VERSION_MAJOR}.${DIST_VERSION_MINOR}${!empty(DIST_VERSION_PATCH):?.:}${DIST_VERSION_PATCH}
PKGNAME=	${DISTNAME:S/otp_doc_man_/erlang-man-/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=erlang/otp/releases/download/OTP-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.erlang.org/
COMMENT=	Documentation for Erlang, a concurrent functional programming language

DIST_SUBDIR=	erlang

# needs erlang installed for its directory structure
DEPENDS+=	erlang>=${PKGVERSION_NOREV}:../../lang/erlang

USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/erlang

do-install:
	cd ${WRKDIR} && pax -rw man ${DESTDIR}${PREFIX}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"

.include "../../mk/bsd.pkg.mk"
