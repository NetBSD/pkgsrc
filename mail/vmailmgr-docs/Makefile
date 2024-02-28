# $NetBSD: Makefile,v 1.2 2024/02/28 15:42:06 schmonz Exp $

.include "../../mail/vmailmgr/Makefile.common"

PKGNAME=		vmailmgr-docs-${VERSION}
CATEGORIES=		mail

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Virtual domain manager for qmail (docs)
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		docs
BUILD_DIRS+=		. authenticate

TOOL_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
TOOL_DEPENDS+=		tex-texinfo-[0-9]*:../../print/tex-texinfo

INSTALLATION_DIRS=	share/doc/vmailmgr

do-install:
	cd ${WRKSRC}; \
	for f in AUTHORS ChangeLog COPYING NEWS TODO \
		doc/ChangeLog* doc/YEAR2000 doc/*.txt doc/*.html \
		commands/*.html authenticate/*.html daemon/*.html \
		scripts/autoresponder.sh; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/doc/vmailmgr/`basename $$f`; \
	done

.include "../../mk/bsd.pkg.mk"
