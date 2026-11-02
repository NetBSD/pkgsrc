# $NetBSD: Makefile,v 1.21 2026/11/02 16:03:40 pin Exp $

DISTNAME=		please-0.6.0
PKGNAME=		pleaser-0.6.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITLAB:=edneville/}
GITLAB_PROJECT=		please
GITLAB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://gitlab.com/edneville/please/
COMMENT=	Sudo like program with regex support
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

WRKSRC=			${WRKDIR}/please-v0.6.0-4815936c6075f1eb8344414ee735d016f93e6e15

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix+=	man/please.1
SUBST_FILES.prefix+=	man/please.ini.5
SUBST_FILES.prefix+=	src/bin/please.rs
SUBST_FILES.prefix+=	src/bin/pleaseedit.rs
SUBST_FILES.prefix+=	src/lib.rs
SUBST_SED.prefix+=	-e 's,/etc/please.ini,${PREFIX}/etc/please.ini,g'
SUBST_SED.prefix+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,/usr/bin/please,${PREFIX}/bin/please,g'

SPECIAL_PERMS+=		bin/please ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		bin/pleaseedit ${SETUID_ROOT_PERMS}

AUTO_MKDIRS=		yes

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.clang}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.clang}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/please \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pleaseedit \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/please.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/please.1
	${INSTALL_MAN} ${WRKSRC}/man/please.ini.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/please.ini.5
	${INSTALL_DATA} ${WRKSRC}/completions/bash/please \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_please \
		${DESTDIR}${PREFIX}/share/zsh/site-functions/

.include "../../lang/rust/cargo.mk"
BUILDLINK_API_DEPENDS.cairo+=	clang>=21
.include "../../lang/clang/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
