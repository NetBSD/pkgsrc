# $NetBSD: Makefile,v 1.83 2022/06/28 11:34:23 wiz Exp $

DISTNAME=	notmuch-0.36
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://notmuchmail.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://notmuchmail.org/
COMMENT=	Mail indexer
LICENSE=	gnu-gpl-v3

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	bash gmake makeinfo pkg-config # perl:test
MAKE_FLAGS+=	PYTHON=${PYTHONBIN}
INFO_FILES=	yes
TEST_TARGET=	check

PYTHON_FOR_BUILD_ONLY=	tool

REPLACE_BASH+=	emacs/notmuch-emacs-mua

.include "options.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--without-ruby

SUBST_CLASSES.SunOS+=	gnuld
SUBST_STAGE.gnuld=	pre-configure
SUBST_FILES.gnuld=	lib/Makefile.local
SUBST_SED.gnuld=	-e 's/-Wl,--[^ ]*//g'

SUBST_CLASSES+=		sphinx
SUBST_SED.sphinx+=	-e "s,sphinx-build,sphinx-build-${PYVERSSUFFIX},"
SUBST_FILES.sphinx+=	bindings/python/docs/Makefile configure doc/Makefile.local
SUBST_STAGE.sphinx=	pre-configure
SUBST_MESSAGE.sphinx=	Fix sphinx command names.

SUBST_CLASSES+=		gpg
SUBST_STAGE.gpg=	pre-configure
SUBST_MESSAGE.gpg=	Select GnuPG command
SUBST_FILES.gpg+=	configure
SUBST_VARS.gpg=		GPGME_GPG

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/sfsexp/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.gmime3+=	gmime3>=3.0.3
.include "../../mail/gmime3/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../devel/talloc/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.5.2
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
