# $NetBSD: Makefile,v 1.17 2005/02/13 16:19:08 taca Exp $
# FreeBSD Id: ports/japanese/namazu2/Makefile,v 1.16 2000/10/26 20:56:25 knu Exp

DISTNAME=	namazu-2.0.14
PKGREVISION=	1
CATEGORIES=	japanese textproc www
MASTER_SITES=	http://www.namazu.org/stable/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.namazu.org/index.html.en
COMMENT=	Full-text search system intended for easy use

DEPENDS+=	p5-File-MMagic>=1.09:../../misc/p5-File-MMagic
DEPENDS+=	p5-Text-Kakasi>=1.04:../../textproc/p5-Text-Kakasi
DEPENDS+=	p5-nkf>=1.7:../../converters/p5-nkf
DEPENDS+=	p5-Text-ChaSen>=1.0:../../textproc/p5-Text-ChaSen

CONFLICTS+=	namazu-[0-9]*

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_PKGINSTALL=		yes
USE_PERL5=		run
GNU_CONFIGURE=		yes
USE_LANGUAGE=		c
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
TEST_TARGET=		check

CONFIGURE_ARGS+= 	--localstatedir=${DATADIR} \
			--libexecdir=${PREFIX}/libexec/cgi-bin \
			--sysconfdir=${PKG_SYSCONFBASE} \
			--with-chasen

DATADIR=		${PREFIX}/libdata
EXAMPLESDIR=		${PREFIX}/share/examples/namazu
EXAMPLES=		mknmzrc namazurc

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	namazu
.for f in ${EXAMPLES}
CONF_FILES+=		${EXAMPLESDIR}/$f	${PKG_SYSCONFDIR}/$f
.endfor
MAKE_DIRS+=		${DATADIR}/namazu/index
OWN_DIRS+=		${PKG_SYSCONFDIR} ${DATADIR}/namazu

post-install:
	${INSTALL_DATA_DIR} ${DATADIR}/namazu
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	cd ${WRKSRC}/conf; ${INSTALL_DATA} $f-sample ${EXAMPLESDIR}/$f
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
