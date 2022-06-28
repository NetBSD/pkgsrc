# $NetBSD: Makefile,v 1.30 2022/06/28 11:33:42 wiz Exp $
#

DISTNAME=	quilt-0.66
PKGREVISION=	4
CATEGORIES=	devel scm
MASTER_SITES=	http://download.savannah.gnu.org/releases/quilt/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/quilt
COMMENT=	Tools to manage series of patches

GNU_CONFIGURE=	yes
USE_TOOLS+=	bash:run gettext-tools gmake msgfmt perl:run gsed

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-cp=${CP}
CONFIGURE_ARGS+=	--with-date=${DATE}
CONFIGURE_ARGS+=	--with-sed=${SED}
.  if exists(/usr/bin/patch)
CONFIGURE_ARGS+=	--with-patch=/usr/bin/patch
.  else
DEPENDS+=		patch>=2.4:../../devel/patch
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/gpatch
.  endif
.else
DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils
DEPENDS+=		patch>=2.4:../../devel/patch

.  if ${OPSYS} == "OpenBSD"
DEPENDS+=		grep-[0-9]*:../../textproc/grep
CONFIGURE_ARGS+=	--with-grep=${PREFIX}/bin/ggrep
.  endif

CONFIGURE_ARGS+=	--with-cp=${PREFIX}/bin/gcp
CONFIGURE_ARGS+=	--with-date=${PREFIX}/bin/gdate
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/gpatch
CONFIGURE_ARGS+=	--with-sed=${PREFIX}/bin/gsed
.endif

CONFIGURE_ARGS+=	--with-sendmail=/usr/sbin/sendmail
CONFIGURE_ARGS+=	--without-rpmbuild
CONFIGURE_ARGS+=	--without-getopt

INSTALL_MAKE_FLAGS+=	BUILD_ROOT=${DESTDIR:Q} etcdir=${PREFIX}/share/examples/quilt

REPLACE_INTERPRETER+=		conf-bash
REPLACE.conf-bash.old=		@BASH@
REPLACE.conf-bash.new=		${BASH}
REPLACE_FILES.conf-bash=	*.in */*.in */*/*.in

SUBST_CLASSES+=		etc
SUBST_MESSAGE.etc=	Fixing path to configuration file.
SUBST_STAGE.etc=	pre-configure
SUBST_SED.etc=		-e 's,/etc/quilt,${PKG_SYSCONFDIR}/quilt,g'
SUBST_FILES.etc=	doc/*

.include "../../mk/bsd.pkg.mk"
