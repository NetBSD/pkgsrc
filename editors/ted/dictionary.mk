# $NetBSD: dictionary.mk,v 1.2 2026/02/12 08:16:49 wiz Exp $

DISTNAME=	ted_${LANGCODE}-2.23-1.noarch
PKGNAME=	ted-${PKG_LANGCODE}-2.23
CATEGORIES=	editors
MASTER_SITES=	https://ftp.nluug.nl/pub/editors/ted/
EXTRACT_SUFX=	.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.nluug.nl/pub/editors/ted/
COMMENT=	${LANGNAME} spelling dictionary for the Ted word processor
LICENSE=	gnu-gpl-v2

DEPENDS+=	ted>=2.23:../../editors/ted

USE_LANGUAGES=	# none
NO_BUILD=	YES

INSTALLATION_DIRS=	share/Ted/dfa

do-install:
	${INSTALL_DATA} ${WRKDIR}/usr/share/Ted/dfa/*.dfa \
		${DESTDIR}${PREFIX}/share/Ted/dfa
