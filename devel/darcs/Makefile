# $NetBSD: Makefile,v 1.70 2023/02/07 01:40:25 pho Exp $

DISTNAME=	darcs-2.16.5
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel scm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.darcs.net/
COMMENT=	Distributed revision control system
LICENSE=	gnu-gpl-v2

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	attoparsec	\
	base	\
	bytestring	\
	constraints	\
	cryptonite	\
	fgl	\
	hashable	\
	memory	\
	regex-tdfa	\
	text	\
	time	\
	unix-compat	\
	vector

# If darcs is to be linked dynamically, it will depend on nearly 140 shared
# objects and the dynamic linker will spend more than a second to resolve
# symbols on startup. This is unacceptable because darcs tends to be
# launched very frequently by users and IDEs. This wastes storage, but time
# is more expensive than disks.
HASKELL_ENABLE_SHARED_LIBRARY=	no

# It makes no sense to build the profiling library because this package
# isn't meant to be used as a library.
HASKELL_ENABLE_LIBRARY_PROFILING=	no

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
.include "../../textproc/hs-regex-base/buildlink3.mk"
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
