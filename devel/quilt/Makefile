# $NetBSD: Makefile,v 1.13 2013/06/14 18:19:17 mspo Exp $
#

DISTNAME=	quilt-0.48
PKGREVISION=	3
CATEGORIES=	devel scm
MASTER_SITES=	http://download.savannah.gnu.org/releases/quilt/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/quilt
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

CONFIGURE_ARGS+=	--with-cp=${PREFIX}/bin/gcp
CONFIGURE_ARGS+=	--with-date=${PREFIX}/bin/gdate
CONFIGURE_ARGS+=	--with-patch=${PREFIX}/bin/gpatch
CONFIGURE_ARGS+=	--with-sed=${PREFIX}/bin/gsed
.endif

CONFIGURE_ARGS+=	--with-sendmail=/usr/sbin/sendmail
CONFIGURE_ARGS+=	--without-rpmbuild
CONFIGURE_ARGS+=	--without-getopt

INSTALL_MAKE_FLAGS+=	BUILD_ROOT=${DESTDIR:Q} etcdir=${PREFIX}/share/examples/quilt

REPLACE_INTERPRETER+=	conf-bash
REPLACE.conf-bash.old=	@BASH@
REPLACE.conf-bash.new=	${BASH}
REPLACE_FILES.conf-bash=*.in */*.in */*/*.in

SUBST_CLASSES+=		bash
SUBST_MESSAGE.bash=	Fixing non-shellbang references to bash.
SUBST_STAGE.bash=	pre-configure
SUBST_SED.bash=		-e 's,@BASH@,${BASH},g'
SUBST_FILES.bash=	quilt/scripts/inspect.in

SUBST_CLASSES+=		etc
SUBST_MESSAGE.etc=	Fixing path to configuration file.
SUBST_STAGE.etc=	pre-configure
SUBST_SED.etc=		-e 's,/etc/quilt,${PKG_SYSCONFDIR}/quilt,g'
SUBST_FILES.etc=	bin/* doc/* po/*

.include "../../mk/bsd.pkg.mk"
