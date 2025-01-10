# $NetBSD: Makefile,v 1.9 2025/01/10 10:37:40 wiz Exp $

DISTNAME=	pandoc-cli-3.6.1
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Conversion between documentation formats
LICENSE=	gnu-gpl-v2

# If pandoc is to be linked dynamically, it will depend on more than 180
# shared objects and the dynamic linker will spend several seconds to
# resolve symbols on startup. This is unacceptable because pandoc tends to
# be launched very frequently by build systems and editors. This wastes
# storage, but time is more expensive than disks.
HASKELL_ENABLE_DYNAMIC_EXECUTABLE=	no

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
post-install:
	cd ${WRKSRC}/man && \
	for f in *.1; do \
		${INSTALL_MAN} $$f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$$f; \
	done

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	pandoc-lua-engine

.include "options.mk"

.include "../../converters/hs-pandoc/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
