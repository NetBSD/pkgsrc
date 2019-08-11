# $NetBSD: Makefile,v 1.17 2019/08/11 13:23:26 wiz Exp $

DISTNAME=	namazu-2.0.21
PKGREVISION=	9
CATEGORIES=	japanese textproc www
MASTER_SITES=	http://www.namazu.org/stable/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.namazu.org/index.html.en
COMMENT=	Full-text search system intended for easy use
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-File-MMagic>=1.25:../../misc/p5-File-MMagic
DEPENDS+=	p5-nkf>=1.7:../../converters/p5-nkf

CONFLICTS+=	namazu-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
TEST_TARGET=		check

BUILD_DEFS+=		PKG_SYSCONFBASE
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/${DATADIR} \
			--libexecdir=${PREFIX}/libexec/cgi-bin \
			--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ENV+=		KAKASI="module_kakasi"
CONFIGURE_ENV+=		ac_cv_path_KAKASI="module_kakasi"
CONFIGURE_ENV+=		CHASEN="module_chasen"
CONFIGURE_ENV+=		ac_cv_path_CHASEN="module_chasen"
CONFIGURE_ENV+=		MECAB="module_mecab"
CONFIGURE_ENV+=		ac_cv_path_MECAB="module_mecab"
DATADIR=		libdata
EXAMPLESDIR=		share/examples/namazu
EXAMPLES=		mknmzrc namazurc
INSTALLATION_DIRS+=	${DATADIR}/namazu ${EXAMPLESDIR}

SUBST_CLASSES+=		wakati
SUBST_STAGE.wakati=	pre-configure
SUBST_FILES.wakati=	pl/conf.pl.in
SUBST_SED.wakati=	-e 's|@OPT_WAKATI_DEFAULT@|none|'

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	namazu
.for f in ${EXAMPLES}
CONF_FILES+=		${EXAMPLESDIR}/${f}	${PKG_SYSCONFDIR}/${f}
.endfor
MAKE_DIRS+=		${DATADIR}/namazu/index
OWN_DIRS+=		${PKG_SYSCONFDIR} ${DATADIR}/namazu

post-install:
.for f in ${EXAMPLES}
	cd ${WRKSRC}/conf && ${INSTALL_DATA} ${f}-sample \
		${DESTDIR}${PREFIX}/${EXAMPLESDIR}/${f}
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
