# $NetBSD: Makefile,v 1.64 2022/02/26 03:57:45 pho Exp $

DISTNAME=	darcs-2.16.4
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel scm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.darcs.net/
COMMENT=	Distributed revision control system
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	share/zsh/site-functions
INSTALLATION_DIRS+=	share/bash-completion/completions
post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/_darcs.zsh \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/_darcs
	${INSTALL_DATA} ${WRKSRC}/contrib/darcs_completion \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/darcs

.include "../../devel/hs-async/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../devel/hs-data-ordlist/buildlink3.mk"
.include "../../devel/hs-fgl/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../textproc/hs-html/buildlink3.mk"
.include "../../www/hs-http-conduit/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../devel/hs-mmap/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../textproc/hs-regex-applicative/buildlink3.mk"
.include "../../textproc/hs-regex-compat-tdfa/buildlink3.mk"
.include "../../archivers/hs-tar/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zip-archive/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
