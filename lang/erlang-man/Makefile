# $NetBSD: Makefile,v 1.16 2024/08/16 09:56:15 adam Exp $

# TODO: on update uncomment DIST_VERSION_PATCH, as doc_man is not available for 27.0.1
DISTNAME=	otp_doc_man_${DIST_VERSION_MAJOR}.${DIST_VERSION_MINOR} #${!empty(DIST_VERSION_PATCH):?.:}${DIST_VERSION_PATCH}
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
	cd ${WRKDIR} && ${PAX} -rw man ${DESTDIR}${PREFIX}/lib/erlang/

.include "../../lang/erlang/Makefile.versions"
.include "../../mk/bsd.pkg.mk"
